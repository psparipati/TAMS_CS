#ifndef ACCOUNTSAVING_H
#define ACCOUNTSAVING_H

#include "Account.h"

class AccountSaving : public Account {
    public:
        // Constructors and destructor
        AccountSaving();
        ~AccountSaving();
        AccountSaving(const AccountSaving& other);
        AccountSaving& operator=(const AccountSaving& other);
        
        // Mutators/Accessors
        void SetMinimumBalance(float minBal);
        float GetMinimumBalance() const;
        
        // Overridden methods
        bool Withdraw(float amount) override;
        Account& operator+=(Account& other) override;
        
    private:
        float minimumBalance;
};

#endif // ACCOUNTSAVING_H