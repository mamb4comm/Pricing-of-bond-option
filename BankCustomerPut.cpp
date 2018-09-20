//BankCostomerPut class member-function definitions.

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <QtDebug>
#include <QMessageBox>
#include "normdist.h"
#include "fin_recipes.h" 
#include "BankCustomerPut.h"

using namespace std;

BankCustomerPut::BankCustomerPut (const string& first, const string& last, const int& id,             //Constructor
                                  double Bond_price, double exer_price, double intr_rate, double vol, double t_mat,
                                  vector <double> c_time, vector<double> c_amount, int step)       
    : BankUser(first, last){
        setIdNumber(id);
        setZeroPrice(Bond_price,exer_price,intr_rate,vol,t_mat);
        setCouponPrice(Bond_price,exer_price,intr_rate,vol,t_mat,c_time,c_amount);
        setAmericanPrice(Bond_price,exer_price,intr_rate,vol,t_mat,step);
    }

BankCustomerPut::~BankCustomerPut() { cout << "\nDestructing BankCustomerPut object\n";}                //Destructor

void BankCustomerPut::setIdNumber (const int& id){

    idNumber = id;
 }

int BankCustomerPut::getIdNumber () const {return idNumber;}

//set memeber function
void BankCustomerPut::setZeroPrice(const double& Bond_price, const double& exer_price, const double& intr_rate, const double& vol, const double& t_mat){
    B = Bond_price;
    X = exer_price;
    r = intr_rate;
    sigma = vol;
    time = t_mat;
}

void BankCustomerPut::setCouponPrice(const double& Bond_price, const double& exer_price, const double& intr_rate, const double& vol, const double& t_mat, const vector <double> c_time, const vector <double> c_amount){
    B = Bond_price;
    X = exer_price;
    r = intr_rate;
    sigma = vol;
    time = t_mat;
    coupon_times = c_time;
    coupon_amounts = c_amount;
}

void BankCustomerPut::setAmericanPrice(const double& Bond_price, const double& exer_price, const double& intr_rate, const double& vol, const double& t_mat, const int& step){
    B = Bond_price;
    X = exer_price;
    r = intr_rate;
    sigma = vol;
    time = t_mat;
    steps = step;
}      

//european put option zero-coupon definition
double BankCustomerPut::bond_option_price_put_zero_black_scholes(const double& B, 
						const double& X, 
						const double& r, 
						const double& sigma,
						const double& time) const{
    double time_sqrt = sqrt(time);
    double d1 = (log(B/X)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    double d2 = d1-(sigma*time_sqrt);
    double p =  X * exp(-r*time) * N(-d2) - B * N(-d1); 
    return p;
}

//european put option coupon definition
double BankCustomerPut::bond_option_price_put_coupon_bond_black_scholes( const double& B,
							const double& X,
							const double& r,
							const double& sigma,
							const double& time, 
							const vector<double> coupon_times, 
							const vector<double> coupon_amounts) const{
    double adjusted_B=B;
    double p1;
    for (unsigned int i=0;i<coupon_times.size();i++) {
	if (coupon_times[i]<=time) {
	    adjusted_B -= coupon_amounts[i] * exp(-r*coupon_times[i]);
	};
    };
    p1 = bond_option_price_put_zero_black_scholes(adjusted_B,X,r,sigma,time);
    return p1;
}

//american put option definition
double BankCustomerPut::bond_option_price_put_american_binomial( const double& B,     
						const double& X,     
						const double& r,     
						const double& sigma, 
						const double& t,     
						const int& steps) const{  // no steps in binomial tree
   double R = exp(r*(t/steps));            // interest rate for each step
   double Rinv = 1.0/R;                    // inverse of interest rate
   double u = exp(sigma*sqrt(t/steps));    // up movement
   double uu = u*u;
   double d = 1.0/u;
   double p_up = (R-d)/(u-d);
   double p_down = 1.0-p_up;
   vector<double> prices(steps+1);       // price of underlying
   vector<double> put_values(steps+1);       // value of corresponding put 
   double values;

   prices[0] = B*pow(d, steps);  // fill in the endnodes.
   for (int i=1; i<=steps; ++i) prices[i] = uu*prices[i-1];
   for (int i=0; i<=steps; ++i) put_values[i] = max(0.0, (X-prices[i])); // put payoffs at maturity
   for (int step=steps-1; step>=0; --step) {
      for (int i=0; i<=step; ++i) {
	 put_values[i] = (p_up*put_values[i+1]+p_down*put_values[i])*Rinv;
	 prices[i] = d*prices[i+1];
	 put_values[i] = max(put_values[i],(X-prices[i]));       // check for exercise
      };
   };
   values = put_values[0];
   return values;
}

//get memeber function                                                                            
double BankCustomerPut::getZeroPrice() const {return bond_option_price_put_zero_black_scholes(B,X,r,sigma,time);}
double BankCustomerPut::getCouponPrice() const {return bond_option_price_put_coupon_bond_black_scholes(B,X,r,sigma,time,coupon_times,coupon_amounts);}
double BankCustomerPut::getAmericanPrice() const {return bond_option_price_put_american_binomial(B,X,r,sigma,time,steps);} 


string BankCustomerPut::toString() const {
    ostringstream output;
    output << fixed << setprecision(6);

    output << BankUser::toString() << endl
           <<BankCustomerPut::getZeroPrice()<<endl
           <<BankCustomerPut::getCouponPrice()<<endl
           <<BankCustomerPut::getAmericanPrice();

    return output.str();
}

bool BankCustomerPut::storePrices(){
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

    priceFile << BankCustomerPut::toString();

    priceFile.close();
    return true;
}


