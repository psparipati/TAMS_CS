#include "Accounts.h"

Accounts::Accounts() {}

Accounts::~Accounts() {
    for (auto account : accounts) {
        delete account;
    }
    accounts.clear();
}

void Accounts::AddAccount(Account* account) {
    accounts.push_back(account);
}

bool Accounts::FindAccount(int accountID) const {
    for (auto account : accounts) {
        if (account->GetAccountID() == accountID) {
            return true;
        }
    }
    return false;
}

Account* Accounts::at(const int i) const {
    if (i >= 0 && i < static_cast<int>(accounts.size())) {
        return accounts[i];
    }
    throw out_of_range("Index out of range");
}

int Accounts::Size() const {
    return static_cast<int>(accounts.size());
}