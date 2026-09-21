#include "AccountSystem.h"

void AccountSystem::AddAccount(Account* account) {
    accts.AddAccount(account);
    cout << "Added new account id " << account->GetAccountID() << " with initial balance $" << fixed << setprecision(2) << account->GetBalance() << endl;
}

int AccountSystem::GetSize() const {
    return accts.Size();
}

bool AccountSystem::FindAccount(int accountID) const {
    return accts.FindAccount(accountID);
}

void AccountSystem::Deposit(int accountID, float amount) {
    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i)->GetAccountID() == accountID) {
            if (accts.at(i)->GetAccountType() == 1) {
                amount -= static_cast<AccountChecking*>(accts.at(i))->GetTransactionFee();
            }
            accts.at(i)->Deposit(amount);
            cout << "Deposited $" << fixed << setprecision(2) << amount << " into account id " << accountID << endl;
            return;
        }
    }
}

void AccountSystem::Withdraw(int accountID, float amount) {
    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i)->GetAccountID() == accountID) {
            if (accts.at(i)->Withdraw(amount)) {
                cout << "Withdrawn $" << fixed << setprecision(2) << amount << " from account id " << accountID << endl;
            }
            return;
        }
    }
}

void AccountSystem::Transfer(int fromAccountID, int toAccountID, float amount) {
    Account* fromAccount = nullptr;
    Account* toAccount = nullptr;

    for (int i = 0; i < accts.Size(); i++) {
        if (accts.at(i)->GetAccountID() == fromAccountID) {
            fromAccount = accts.at(i);
        }
        if (accts.at(i)->GetAccountID() == toAccountID) {
            toAccount = accts.at(i);
        }
    }

    if (fromAccount && toAccount) {
        float totalDebit = amount;
        // If source is checking account, add transaction fee
        if (fromAccount->GetAccountType() == 1) {
            totalDebit += static_cast<AccountChecking*>(fromAccount)->GetTransactionFee();
        }
        
        // Check if source account can afford the transfer (including fees and minimum balance)
        bool canTransfer = false;
        if (fromAccount->GetAccountType() == 1) {
            // Checking account - just need sufficient funds
            if (fromAccount->GetBalance() >= totalDebit) {
                canTransfer = true;
            }
        }
        else {
            // Saving account - must maintain minimum balance
            if ((fromAccount->GetBalance() - totalDebit) >= static_cast<AccountSaving*>(fromAccount)->GetMinimumBalance()) {
                canTransfer = true;
            }
        }
        
        if (canTransfer) {
            fromAccount->SetBalance(fromAccount->GetBalance() - totalDebit);
            toAccount->Deposit(amount);
            cout << "Successfully transferred amount $" << fixed << setprecision(2) << amount << " from source account id " << fromAccountID << " to destination account id " << toAccountID << endl;
        } else {
            if (fromAccount->GetAccountType() == 1) {
                cout << "Insufficient funds for transfer." << endl;
            } else {
                cout << "Transfer would violate minimum balance requirement." << endl;
            }
        }
    }
}

void AccountSystem::DisplayAll() const {
    cout << "+--------------------------------------------------------------------------+" << endl;
    cout << "| Acct | Customer Account Name  | Balance         | Type      | Fee/Min.   |" << endl;

    for (int i = 0; i < accts.Size(); i++) {
        cout << "+--------------------------------------------------------------------------+" << endl;
        string typeStr = (accts.at(i)->GetAccountType() == 1) ? "Checking" : "Saving";
        float feeOrMin = (accts.at(i)->GetAccountType() == 1) ? 
            static_cast<AccountChecking*>(accts.at(i))->GetTransactionFee() : 
            static_cast<AccountSaving*>(accts.at(i))->GetMinimumBalance();
        cout << "| " << setw(4) << right << accts.at(i)->GetAccountID() << " | "
             << setw(22) << left << accts.at(i)->GetCustName() << " | $"
             << setw(14) << right << fixed << setprecision(2) << accts.at(i)->GetBalance() << " | "
             << setw(9) << left << typeStr << " | $"
             << setw(9) << right << fixed << setprecision(2) << feeOrMin << " |" << endl;
    }
    cout << "+--------------------------------------------------------------------------+" << endl;
}