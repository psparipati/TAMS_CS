#include "Accounts.h"

Accounts::Accounts() : MAX_SIZE(1000), accounts(new Account[MAX_SIZE]), size(0) {}

Accounts::~Accounts() {
    delete[] accounts;
}

void Accounts::AddAccount(const Account& account) {
    if (size < MAX_SIZE) {
        accounts[size] = account;
        size++;
    }
}

bool Accounts::FindAccount(int accountID) const {
    for (int i = 0; i < size; i++) {
        if (accounts[i].GetAccountID() == accountID) {
            return true;
        }
    }
    return false;
}

Account& Accounts::at(const int i) const {
    if (i >= 0 && i < size) {
        return accounts[i];
    }
    throw std::out_of_range("Index out of range");
}

int Accounts::Size() const {
    return size;
}