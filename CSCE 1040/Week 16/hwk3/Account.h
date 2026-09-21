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
        virtual ~Account();
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
        void SetAccountType(int type);
        int GetAccountType() const;
        
        // Virtual methods for polymorphism
        virtual void Deposit(float amount);
        virtual bool Withdraw(float amount);
        virtual Account& operator+=(Account& other);
        
    private:
        int* accountID;
        string custName;
        float balance;
        int accountType; // Checking = 1, Saving = 2
};

#endif // ACCOUNT_H