#ifndef ACCOUNTCHECKING_H
#define ACCOUNTCHECKING_H

#include "Account.h"

class AccountChecking : public Account {
    public:
        // Constructors and destructor
        AccountChecking();
        ~AccountChecking();
        AccountChecking(const AccountChecking& other);
        AccountChecking& operator=(const AccountChecking& other);
        
        // Mutators/Accessors
        void SetTransactionFee(float fee);
        float GetTransactionFee() const;
        
        // Overridden methods
        void Deposit(float amount) override;
        bool Withdraw(float amount) override;
        Account& operator+=(Account& other) override;
        
    private:
        float transactionFee;
};

#endif // ACCOUNTCHECKING_H