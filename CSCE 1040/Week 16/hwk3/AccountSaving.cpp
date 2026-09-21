#include "AccountSaving.h"

// Default constructor
AccountSaving::AccountSaving() : minimumBalance(100.0f) {
    SetAccountType(2); // Saving account type
}

// Destructor
AccountSaving::~AccountSaving() {}

// Copy constructor
AccountSaving::AccountSaving(const AccountSaving& other) : Account(other), minimumBalance(other.minimumBalance) {}

// Copy assignment operator
AccountSaving& AccountSaving::operator=(const AccountSaving& other) {
    if (this != &other) {
        Account::operator=(other);
        minimumBalance = other.minimumBalance;
    }
    return *this;
}

void AccountSaving::SetMinimumBalance(float minBal) {
    minimumBalance = minBal;
}

float AccountSaving::GetMinimumBalance() const {
    return minimumBalance;
}

bool AccountSaving::Withdraw(float amount) {
    if (amount > 0 && (GetBalance() - amount) >= minimumBalance) {
        SetBalance(GetBalance() - amount);
        return true;
    }
    else {
        cout << "Error: failed to withdraw $" << fixed << setprecision(2) << amount << " from account id " << GetAccountID() << endl;
        return false;
    }
}

Account& AccountSaving::operator+=(Account& other) {
    float transferAmount = 100.0f;
    
    if ((GetBalance() - transferAmount) >= minimumBalance) {
        SetBalance(GetBalance() - transferAmount);
        other.Deposit(transferAmount);
    }
    else {
        cout << "Transfer would violate minimum balance requirement." << endl;
    }
    return *this;
}