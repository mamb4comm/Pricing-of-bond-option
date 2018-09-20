//BankCustomer (only call option) derived from BankUser

#ifndef CUSTOMERCALL_H
#define CUSTOMERCALL_H

#include <string>
#include <vector>
#include "BankUser.h"
#include "normdist.h"

class BankCustomerCall : public BankUser {

    friend class BankOfficer;

    public:
    BankCustomerCall (const std::string&, const std::string&, const int&,
                        double, double, double, double, double, double, double, int);
    ~BankCustomerCall ();

    virtual void setIdNumber(const int&) override;
    virtual int getIdNumber() const override;

    void setAmericanCall(const double&, const double&, const double&, const double&, const double&,const double&, const double&, const int&);

    double getAmericanCallPrice () const;

    
    //call option with Rendlemann&Bartter orinal alghoritm
    double bond_option_price_call_zero_american_rendleman_bartter (const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const int&) const;
    
    virtual std::string toString() const override;
    bool storePrices();


    private:

    int idNumber;

    double X;
    double option_maturity;
    double S;
    double M;
    double interest;
    double bond_maturity;
    double maturity_payment;
    int no_steps;
};

#endif
