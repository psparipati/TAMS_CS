#include "Account.h"
#include "Accounts.h"
#include "AccountSystem.h"

void Header() {
    cout << "+----------------------------------------------+" << endl;
    cout << "|    Texas Academy of Mathematics and Science  |" << endl;
    cout << "|       CSCE 1040 - Computer Science II        |" << endl;
    cout << "|  Prabhav Paripati  pp1046  pp1046@my.unt.edu |" << endl;
    cout << "+----------------------------------------------+" << endl;
}

int Get_Choice() {
    int choice;
    cout << "+--------------------------------------+" << endl;
    cout << "| Enter account selection:             |" << endl;
    cout << "| 1 : Add new account                  |" << endl;
    cout << "| 2 : Deposit into account             |" << endl;
    cout << "| 3 : Withdraw from account            |" << endl;
    cout << "| 4 : Transfer into account            |" << endl;
    cout << "| 5 : Display all accounts             |" << endl;
    cout << "| 6 : End transaction (Exit)           |" << endl;
    cout << "+--------------------------------------+" << endl;
    cin >> choice;
    return choice;
}

void Menu(AccountSystem& system) {
    int choice;
    do {
        choice = Get_Choice();
        switch (choice) {
            case 1: {
                cout << "Enter account type (1: Checking, 2: Savings): ";
                int type;
                cin >> type;
                
                if (type != 1 && type != 2) {
                    cout << "Error: invalid account type. Account type (1: checking, 2: saving)" << endl;
                    break;
                }
                
                int id;
                string name;
                float balance;
                cout << "Enter account ID: ";
                cin >> id;
                
                if (system.FindAccount(id)) {
                    cout << "Error: account id " << id << " already exists." << endl;
                    break;
                }
                
                cout << "Enter customer account name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial deposit amount: $";
                cin >> balance;
                
                if (type == 1) {
                    AccountChecking* newAccount = new AccountChecking();
                    cout << "Enter the transaction fee: $";
                    float fee;
                    cin >> fee;
                    newAccount->SetAccountID(id);
                    newAccount->SetCustName(name);
                    newAccount->SetBalance(balance);
                    newAccount->SetTransactionFee(fee);
                    system.AddAccount(newAccount);
                }

                else if (type == 2) {
                    AccountSaving* newAccount = new AccountSaving();
                    cout << "Enter the minimum balance: $";
                    float minBal;
                    cin >> minBal;
                    newAccount->SetAccountID(id);
                    newAccount->SetCustName(name);
                    newAccount->SetBalance(balance);
                    newAccount->SetMinimumBalance(minBal);
                    system.AddAccount(newAccount);
                }
                break;
            }
            case 2: {
                if (system.GetSize() == 0) {
                    cout << "Empty account list." << endl;
                    break;
                }
            
                int id;
                float amount;
                cout << "Enter account id: ";
                cin >> id;
            
                if (system.FindAccount(id) == false) {
                    cout << "Error: account with id " << id << " not found." << endl;
                    break;
                }
            
                cout << "Enter the deposit amount: $";
                cin >> amount;
                system.Deposit(id, amount);
                break;
            }
            case 3: {
                if (system.GetSize() == 0) {
                    cout << "Empty account list." << endl;
                    break;
                }
            
                int id;
                float amount;
                cout << "Enter account id: ";
                cin >> id;
            
                if (system.FindAccount(id) == false) {
                    cout << "Error: account with id " << id << " not found." << endl;
                    break;
                }
            
                cout << "Enter the withdraw amount: $";
                cin >> amount;
                system.Withdraw(id, amount);
                break;
            }
            case 4: {
                if (system.GetSize() == 0) {
                    cout << "Empty account list." << endl;
                    break;
                }
            
                int fromID, toID;
                float amount;
                cout << "Enter source account id: ";
                cin >> fromID;
                cout << "Enter destination account id: ";
                cin >> toID;
            
                if (system.FindAccount(fromID) == false || system.FindAccount(toID) == false) {
                    cout << "Error: Source or destination account number not found. Operation failed." << endl;
                    break;
                }
            
                cout << "Enter the transfer amount: $";
                cin >> amount;
                system.Transfer(fromID, toID, amount);
                break;
            }
            case 5: {
                if (system.GetSize() == 0) {
                    cout << "Empty account list." << endl;
                    break;
                }
            
                system.DisplayAll();
                break;
            }
            case 6:
                cout << "Thank you for running the program. Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid selection. Enter a value between 1-6." << endl;
        }
        cout << endl;
    } while (choice != 6);
}

int main() {
    AccountSystem system;
    Header();
    Menu(system);
    return 0;
}