#include "Account.h"

// Default constructor
Account::Account() : accountID(new int), custName(""), balance(0.0f), accountType(0) {}

// Destructor
Account::~Account() {
    delete accountID;
}

// Copy constructor
Account::Account(const Account& other) : accountID(new int(*(other.accountID))), custName(other.custName), balance(other.balance), accountType(other.accountType) {}

// Copy assignment operator
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        delete accountID; // Free existing resource
        accountID = new int(*(other.accountID)); // Deep copy
        custName = other.custName;
        balance = other.balance;
        accountType = other.accountType;
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

void Account::SetAccountType(int type) {
    accountType = type;
}

int Account::GetAccountType() const {
    return accountType;
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

bool Account::Withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    else {
        cout << "Insufficient funds or invalid amount." << endl;
        return false;
    }
}

// Overloaded += operator for transfers
Account& Account::operator+=(Account& other) {
    float transferAmount = 100.0f;
    if (this->balance >= transferAmount) {
        this->balance -= transferAmount;
        other.balance += transferAmount;
    }
    else {
        cout << "Insufficient funds for transfer." << endl;
    }
    return *this;
}