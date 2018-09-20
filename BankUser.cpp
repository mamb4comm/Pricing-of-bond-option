//Abstract base class BankUser member-function definition (except pure virtual function)

#include <sstream>
#include "BankUser.h"
using namespace std;

BankUser::BankUser(const string& first, const string& last)
    : firstName(first), lastName(last) {}

void BankUser::setFirstName (const string& first) {firstName = first;}

string BankUser::getFirstName () const {return firstName;}

void BankUser::setLastName (const string& last) {lastName = last;}

string BankUser::getLastName () const {return lastName;}

string BankUser::toString () const {
    return getFirstName() + " "s + getLastName(); 
}
