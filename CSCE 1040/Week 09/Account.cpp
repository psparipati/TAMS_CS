#include "Account.h"

// Default constructor
Account::Account() : accountID(new int), custName(""), balance(0.0f) {}

// Destructor
Account::~Account() {
    delete accountID;
}

// Copy constructor
Account::Account(const Account& other) : accountID(new int(*(other.accountID))), custName(other.custName), balance(other.balance) {}

// Copy assignment operator
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        delete accountID; // Free existing resource
        accountID = new int(*(other.accountID)); // Deep copy
        custName = other.custName;
        balance = other.balance;
    }
    return *this;
}

// Mutators/Accessors for all attributes
void Account::SetAccountID(int id) {
    *accountID = id;
}

int Account::GetAccountID() const {
    return *accountID;
}

void Account::SetCustName(string name) {
    custName = name;
}

string Account::GetCustName() const {
    return custName;
}

void Account::SetBalance(float bal) {
    balance = bal;
}

float Account::GetBalance() const {
    return balance;
}

// Deposit and Withdraw methods
void Account::Deposit(float amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        cout << "Invalid deposit amount." << endl;
    }
}

void Account::Withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds or invalid amount." << endl;
    }
}

// Overloaded += operator for transfers
Account& Account::operator+=(const Account& other) {
    this->balance += other.balance;
    return *this;
}