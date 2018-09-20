//BankCustomerCall class member-function definition

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <QMessageBox>
#include "normdist.h"
#include "fin_recipes.h" 
#include "BankCustomerCall.h"

using namespace std;

BankCustomerCall::BankCustomerCall (const string& first, const string& last, const int& id,                //Consturctor
                                    double Bond_price, double opt_mat, double sigma, double t_struct, double intr, double bond_mat, double mat_pay, int n_step)
    : BankUser(first, last) {
        
         setIdNumber(id);
         setAmericanCall(Bond_price,opt_mat,sigma,t_struct,intr,bond_mat,mat_pay,n_step);

    }

BankCustomerCall::~BankCustomerCall()  {cout << "\nDestructing BankCustomerCall object\n";}             //Destructor

void BankCustomerCall::setIdNumber(const int& id){

    idNumber = id;
}

int BankCustomerCall::getIdNumber () const {return idNumber;} 

void BankCustomerCall::setAmericanCall (const double& Bond_price, const double& opt_mat, const double& sigma, 
                                         const double& t_struct, const double& intr, const double& bond_mat, const double& mat_pay, const int& n_step){
    X = Bond_price;
    option_maturity = opt_mat;
    S = sigma;
    M = t_struct;
    interest = intr;
    bond_maturity = bond_mat;
    maturity_payment = mat_pay;
    no_steps = n_step;
    }

//call option with Rendleman&Bartter orinal alghoritm definition
double BankCustomerCall::bond_option_price_call_zero_american_rendleman_bartter(const double& X,  
							      const double& option_maturity, 
							      const double& S, 
							      const double& M,    // term structure paramters
							      const double& interest, // current short interest rate
							      const double& bond_maturity, // time to maturity for underlying bond
							      const double& maturity_payment,
							      const int& no_steps) const{     
    double delta_t = bond_maturity/no_steps;
 
    double u=exp(S*sqrt(delta_t));
    double d=1/u;
    double p_up = (exp(M*delta_t)-d)/(u-d);
    double p_down = 1.0-p_up;

    vector<double> r(no_steps+1);
    r[0]=interest*pow(d,no_steps);
    double uu=u*u;
    for (int i=1;i<=no_steps;++i){ r[i]=r[i-1]*uu;};
    vector<double> P(no_steps+1);
    for (int i=0;i<=no_steps;++i){ P[i] = maturity_payment; };
    int no_call_steps=int(no_steps*option_maturity/bond_maturity);
    for (int curr_step=no_steps;curr_step>no_call_steps;--curr_step) {
	for (int i=0;i<curr_step;i++) {
	    r[i] = r[i]*u;
	    P[i] = exp(-r[i]*delta_t)*(p_down*P[i]+p_up*P[i+1]); 
 	};
    };
    vector<double> C(no_call_steps+1);
    for (int i=0;i<=no_call_steps;++i){ C[i]=max(0.0,P[i]-X); };
    for (int curr_step=no_call_steps;curr_step>=0;--curr_step) {
	for (int i=0;i<curr_step;i++) {
	    r[i]  = r[i]*u;
	    P[i] = exp(-r[i]*delta_t)*(p_down*P[i]+p_up*P[i+1]); 
	    C[i]=max(P[i]-X, exp(-r[i]*delta_t)*(p_up*C[i+1]+p_down*C[i]));
 	};
    };
    return C[0];
}

double BankCustomerCall::getAmericanCallPrice() const {return bond_option_price_call_zero_american_rendleman_bartter(X,option_maturity,S,M,interest,bond_maturity,maturity_payment,no_steps);}



string BankCustomerCall::toString() const {
    ostringstream output;
    output << fixed << setprecision(6);
    output <<"\n"<< BankCustomerCall::getAmericanCallPrice();
    return output.str();
}

bool BankCustomerCall::storePrices(){
    ofstream priceFile;
    QMessageBox msg;
    string pathFile = "Client_price/client_" + to_string(idNumber) + ".txt";
    msg.setText(QString::fromStdString(pathFile));
    msg.exec();
    try {
        priceFile.open(pathFile.c_str(), ios::out | ios::app);
    } catch (exception e) {

        msg.setText(  e.what());
        msg.exec();
    }

    if(!priceFile.is_open()){
        return false;
    }

    priceFile << BankCustomerCall::toString();

    priceFile.close();
    return true;
}
