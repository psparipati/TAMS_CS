#include "AccountSystem.h"

void AccountSystem::AddAccount(const Account& account) {
    accts.AddAccount(account);
    cout << "Added new account id " << account.GetAccountID() << " with initial balance $" << fixed << setprecision(2) << account.GetBalance() << endl;
}

int AccountSystem::GetSize() const {
    return accts.Size();
}

bool AccountSystem::FindAccount(int accountID) const {
    return accts.FindAccount(accountID);
}

void AccountSystem::Deposit(int accountID, float amount) {
    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i).GetAccountID() == accountID) {
            accts.at(i).Deposit(amount);
            cout << "Deposited $" << fixed << setprecision(2) << amount << " into account id " << accountID << endl;
            return;
        }
    }
}

void AccountSystem::Withdraw(int accountID, float amount) {
    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i).GetAccountID() == accountID) {
            if (accts.at(i).GetBalance() < amount) {
                cout << "Error: failed to withdraw $" << fixed << setprecision(2) << amount << " from account id " << accountID << endl;
                return;
            }
            accts.at(i).Withdraw(amount);
            cout << "Withdrawn $" << fixed << setprecision(2) << amount << " from account id " << accountID << endl;
            return;
        }
    }
}

void AccountSystem::Transfer(int fromAccountID, int toAccountID, float amount) {
    Account* fromAccount = nullptr;
    Account* toAccount = nullptr;

    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i).GetAccountID() == fromAccountID) {
            fromAccount = &accts.at(i);
        }
        if (accts.at(i).GetAccountID() == toAccountID) {
            toAccount = &accts.at(i);
        }
    }

    if (fromAccount->GetBalance() < amount) {
        cout << "Error: Insufficient balance. Source account has only $" << fixed << setprecision(2) << fromAccount->GetBalance() << " in the balance." << endl;
        return;
    }

    fromAccount->Withdraw(amount);
    toAccount->Deposit(amount);
    cout << "Successfully transferred amount $" << fixed << setprecision(2) << amount << " from source account id " << fromAccountID << " to destination account id " << toAccountID << endl;
}

void AccountSystem::DisplayAll() const {
    cout << "+--------------------------------------------------------+" << endl;
    cout << "| Acct | Customer Account Name        | Balance          |" << endl;

    for (int i = 0; i < accts.Size(); i++) {
        cout << "+--------------------------------------------------------+" << endl;
        cout << "| " << setw(4) << right << accts.at(i).GetAccountID() << " | "
             << setw(28) << left << accts.at(i).GetCustName() << " | $"
             << setw(15) << right << fixed << setprecision(2) << accts.at(i).GetBalance() << " |" << endl;
    }
    cout << "+--------------------------------------------------------+" << endl;
}