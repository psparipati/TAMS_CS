#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include "Accounts.h"
#include "AccountChecking.h"
#include "AccountSaving.h"

class AccountSystem {
    public:
        void AddAccount(Account* account);
        void Deposit(int accountID, float amount);
        void Withdraw(int accountID, float amount);
        void Transfer(int fromAccountID, int toAccountID, float amount);
        void DisplayAll() const;
        bool FindAccount(int accountID) const;
        int GetSize() const;
        
    private:
        Accounts accts;
};

#endif // ACCOUNTSYSTEM_H