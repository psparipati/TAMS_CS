#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"
#include <vector>

class Accounts {
    public:
        Accounts();
        ~Accounts();
        void AddAccount(Account* account);
        bool FindAccount(int accountID) const;
        int Size() const;
        Account* at(const int i) const;
    private:
        std::vector<Account*> accounts;
};

#endif // ACCOUNTS_H