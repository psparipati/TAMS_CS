#include "AccountChecking.h"

// Default constructor
AccountChecking::AccountChecking() : Account(), transactionFee(0.0f) {
    SetAccountType(1); // Checking account type
}

// Destructor
AccountChecking::~AccountChecking() {}

// Copy constructor
AccountChecking::AccountChecking(const AccountChecking& other) : Account(other), transactionFee(other.transactionFee) {}

// Copy assignment operator
AccountChecking& AccountChecking::operator=(const AccountChecking& other) {
    if (this != &other) {
        Account::operator=(other);
        transactionFee = other.transactionFee;
    }
    return *this;
}

void AccountChecking::SetTransactionFee(float fee) {
    transactionFee = fee;
}

float AccountChecking::GetTransactionFee() const {
    return transactionFee;
}

void AccountChecking::Deposit(float amount) {
    if (amount > 0) {
        SetBalance(GetBalance() + amount);
    }
}

bool AccountChecking::Withdraw(float amount) {
    float totalAmount = amount + transactionFee;
    if (totalAmount > 0 && totalAmount <= GetBalance()) {
        SetBalance(GetBalance() - totalAmount);
        return true;
    }
    else {
        cout << "Insufficient funds or invalid amount." << endl;
        return false;
    }
}

Account& AccountChecking::operator+=(Account& other) {
    float transferAmount = 100.0f;
    float totalAmount = transferAmount + transactionFee;
    
    if (GetBalance() >= totalAmount) {
        SetBalance(GetBalance() - totalAmount);
        other.Deposit(transferAmount);
    }
    else {
        cout << "Insufficient funds for transfer." << endl;
    }
    return *this;
}