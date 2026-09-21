#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include "Accounts.h"

class AccountSystem {
    public:
        void AddAccount(const Account& account);
        void Deposit(int accountID, float amount);
        void Withdraw(int accountID, float amount);
        void Transfer(int fromAccountID, int toAccountID, float amount);
        void DisplayAll() const;
        bool FindAccount(int accountID) const;
        int GetSize() const;
    private:
        Accounts accts = Accounts();
};

#endif // ACCOUNTSYSTEM_H