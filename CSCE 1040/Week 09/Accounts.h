#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"

class Accounts {
    public:
        Accounts();
        ~Accounts();
        void AddAccount(const Account& account);
        bool FindAccount(int accountID) const;
        int Size() const;
        Account& at(const int i) const;
    private:
        const int MAX_SIZE;
        Account* accounts;
        int size;
};

#endif // ACCOUNTS_H