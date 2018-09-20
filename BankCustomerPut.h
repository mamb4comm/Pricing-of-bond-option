//BankCustomer (only put option) derived from BankUser

#ifndef CUSTOMERPUT_H
#define CUSTOMERPUT_H

#include <string>
#include <vector>
#include "BankUser.h"
#include "normdist.h"


class BankCustomerPut : public BankUser {

    public:
    
    BankCustomerPut (const std::string&, const std::string&, const int&,
                     double, double, double, double, double,
                     std::vector <double>, std::vector<double>, int);
    ~BankCustomerPut ();

    virtual void setIdNumber(const int&) override;
    virtual int getIdNumber() const override;

     void setZeroPrice (const double&, const double&, const double&, const double&, const double&);
     void setCouponPrice (const double&, const double&, const double&, const double&, const double&, const std::vector <double>, const std::vector<double>);
     void setAmericanPrice (const double&, const double&, const double&, const double&, const double&, const int&);


    //get function to return option prices
    double getZeroPrice () const;
    double getCouponPrice() const;
    double getAmericanPrice() const;
    

    //european put option zero-coupon
    virtual double bond_option_price_put_zero_black_scholes (const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&) const;

    //european put option coupon
    virtual double bond_option_price_put_coupon_bond_black_scholes (const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const std::vector <double>,
                                                                    const std::vector <double>) const;

    //american put option
    virtual double bond_option_price_put_american_binomial (const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const int&) const;
  
    virtual std::string toString() const override;
    bool storePrices();


    private:
    int idNumber;
    
    //european put option zero-coupon parameters
    
    double B;       //bond price
    double X;       //exercise price 
    double r;       // interest rate
    double sigma;   //volatility
    double time;    //time to maturity

    //european put option coupon parameters
    
    std::vector <double> coupon_times;
    std::vector <double> coupon_amounts;
    
    //american put option parameters
    
    int steps;


   // double price1; 
};

#endif
