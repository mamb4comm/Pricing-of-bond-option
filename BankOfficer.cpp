//BankOfficer class member-function definition
/*
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <QMessageBox>
#include "BankOfficer.h"
#include "BankCustomerPut.h"
#include "BankCustomerCall.h"

using namespace std;

BankOfficer::BankOfficer (const string& first, const string& last, const int& id)
    :BankUser (first,last){
        setIdNumber(id);
    }

BankOfficer::~BankOfficer() {cout << "\nDestructing BankOfficer object\n";}

void BankOfficer::setIdNumber (const int& id){
  //  if(id != 5){
  //      throw invalid_argument("Customer id number must be 5 digits");
  //  }

    idNumber = id;
}

int BankOfficer::getIdNumber() const {return idNumber;}


string BankOfficer::toString() const {
    ostringstream output;
    output << fixed << setprecision(6);
    output << BankUser::toString()
           << "\nOfficier ID: "
           << BankOfficer::getIdNumber();
    return output.str(); 
}

bool BankOfficer::openFile(const string& pathFile){
    ifstream priceFile;
    QMessageBox msg;
   // string pathFile = "Client_price/client_" + to_string(idNumber) + ".txt";
   // msg.setText(QString::fromStdString(pathFile));
   // msg.exec();
    try {
        priceFile.open(pathFile.c_str(), ios::in);
    } catch (exception e) {

        msg.setText(  e.what());
        msg.exec();
    }

 //   if(!priceFile.is_open()){
 //       cerr << "Fail to open the file";
 //   }
    char ch;
    while(!priceFile.eof())
     {
       priceFile.get(ch);
       cout << ch;
     }
     priceFile.close();
     return true;
}


//PURE FUNCTION not usefull
double BankOfficer::bond_option_price_put_zero_black_scholes (const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&) const {;}
                                        
double BankOfficer::bond_option_price_put_coupon_bond_black_scholes (const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const std::vector <double>,
                                                                    const std::vector <double>) const {;}

double BankOfficer::bond_option_price_put_american_binomial (const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const int&) const {;}

double BankOfficer::bond_option_price_call_zero_american_rendleman_bartter (const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const int&) const {;}


void BankOfficer::setZeroPrice (const double&, const double&, const double&, const double&, const double&) {;}
void BankOfficer::setCouponPrice (const double&, const double&, const double&, const double&, const double&, const std::vector <double>, const std::vector<double>){;}
void BankOfficer::setAmericanPrice (const double&, const double&, const double&, const double&, const double&, const int&){;}
void BankOfficer::setAmericanCall(const double&, const double&, const double&, const double&, const double&,const double&, const double&, const int&) {;}

double BankOfficer::getZeroPrice () const {;}
double BankOfficer::getCouponPrice() const {;}
double BankOfficer::getAmericanPrice() const {;}
double BankOfficer::getAmericanCallPrice() const {;}
*/



