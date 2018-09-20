//Bank Officier class derived from BankUser base class
/*
#ifndef BANKOFFICER_H
#define BANKOFFICER_H

#include <string>
#include "BankUser.h"
#include "normdist.h"



class BankOfficer : public BankUser {

    public:
    //friend class BankCustomerPut;
    //friend class BankCustomerCall;

    BankOfficer(const std::string&, const std::string&, const int&);
    ~BankOfficer ();

    virtual void setIdNumber (const int&) override;
    virtual int getIdNumber() const override;

    virtual double getZeroPrice () const override;
    virtual double getCouponPrice() const override;
    virtual double getAmericanPrice() const override;
    virtual double getAmericanCallPrice() const override;

    virtual std::string toString() const override;
    bool openFile(const std::string&);


    //PURE FUNCTION not usefull
    virtual double bond_option_price_put_zero_black_scholes (const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&,
                                                                const double&) const override;
                                        
    virtual double bond_option_price_put_coupon_bond_black_scholes (const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const double&,
                                                                    const std::vector <double>,
                                                                    const std::vector <double>) const override;

    virtual double bond_option_price_put_american_binomial (const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const double&,
                                                            const int&) const override;

    virtual double bond_option_price_call_zero_american_rendleman_bartter (const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const double&,
                                                                            const int&) const override;

    virtual void setZeroPrice (const double&, const double&, const double&, const double&, const double&) override;
    virtual void setCouponPrice (const double&, const double&, const double&, const double&, const double&, const std::vector <double>, const std::vector<double>)override;
    virtual void setAmericanPrice (const double&, const double&, const double&, const double&, const double&, const int&)override;
    virtual void setAmericanCall(const double&, const double&, const double&, const double&, const double&,const double&, const double&, const int&) override;

    //END OF USELESS PURE VIRTUAL FUNCTION


    
    private:

    int idNumber;
    //enum class RequestType {Put_REQUEST=1, CALL_REQUEST, ZERO_REQUEST, CLOSE};

};

#endif 
*/
