//main programm to test BankCustomerCall

#include <vector>
#include <iostream>
#include "BankUser.h"
#include "BankCustomerPut.h"
#include "BankCustomerCall.h"
#include "BankOfficer.h"


using namespace std;

//void virtualViaPointer(const BankUser* const); // prototype


void virtualViaReference(const BankUser&); // prototype


int main(){

    BankCustomerPut bankPut {"Giorgio", "Amici", 7896, 100, 100, 0.05, 0.1, 1, {0.5}, {1}, 100};
    BankCustomerPut bankPut1 {"Chiara", "Bianchi", 6452, 100, 100, 0.05, 0.1, 1, {0.5}, {1}, 100};
    BankCustomerCall bankCall {"Guido", "Rossi", 8547, 950, 4, 0.15, 0.05, 0.10, 5, 1000, 100};
    BankOfficer bankOfficer {"Luca", "Felici", 12376};

    vector <BankUser*> bankUser{&bankPut, &bankPut1, &bankCall, &bankOfficer};

    //cout <<"\n" << BankUser.zeroPrice << endl;

    //for (const BankUser* bankUserPtr : bankUser){
    //    virtualViaPointer(bankUserPtr);
    //}

    for (const BankUser* bankUserPtr : bankUser){
        virtualViaReference(*bankUserPtr);
    }

}

//void virtualViaPointer (const BankUser* const baseClassPtr){
//    cout<< baseClassPtr->toString();
//}

void virtualViaReference (const BankUser& baseClassRef){
    cout << baseClassRef.toString() << endl;
    //cout << baseClassRef.zeroPrice;
    //baseClassRef.writeInfo();
}