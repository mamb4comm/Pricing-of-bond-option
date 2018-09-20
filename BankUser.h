//Bank abstract base class

#ifndef BANKUSER_H
#define BANKUSER_H

#include <string>
#include <vector>


class BankUser {

    public: 
    BankUser (const std::string&, const std::string&);
    virtual ~BankUser() = default;

    void setFirstName (const std::string&);
    std::string getFirstName () const;

    void setLastName (const std::string&);
    std::string getLastName () const;

    
    //PURE VIRTUAL FUNCTION that every derived class should implement

    virtual void setIdNumber (const int&) =0;
    virtual int getIdNumber() const = 0;
    
  
    
    //VIRTUAL FUNCTION that every derived class could override
    virtual std::string toString() const;



    //Function that only BankOfficier should implement
    
    protected:
    std::string firstName;
    std::string lastName;
};

#endif 
