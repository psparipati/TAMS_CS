#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account {
    public:
        // Default constructor
        Account();
        // Destructor
        ~Account();
        // Copy constructor
        Account(const Account& other);
        // Copy assignment operator
        Account& operator=(const Account& other);
        // Mutators/Accessors for all attributes
        void SetAccountID(int id);
        int GetAccountID() const;
        void SetCustName(string name);
        string GetCustName() const;
        void SetBalance(float bal);
        float GetBalance() const;
        // Deposit and Withdraw methods
        void Deposit(float amount);
        void Withdraw(float amount);
        // Overloaded += operator for transfers
        Account& operator+=(const Account& other);
    private:
        int* accountID;
        string custName;
        float balance;
};

#endif // ACCOUNT_H