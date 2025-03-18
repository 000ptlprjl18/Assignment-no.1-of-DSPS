#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string Name;
    int accountNumber;
    double balanceAmount;

public:
    
    BankAccount(string name = "", int x = 0, double balance = 0) {
        Name = name;
        accountNumber = x;
        balanceAmount = balance;
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balanceAmount += amount;
            cout << "\nAmount deposited successfully.";
        } else {
            cout << "\nInvalid deposit amount.";
        }
    }

    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balanceAmount) {
            balanceAmount -= amount;
            cout << "\nAmount withdrawn successfully.";
        } else {
            cout << "\nInvalid withdraw amount or insufficient balance.";
        }
    }

    
    void display() 
    {
        cout << Name;
        for (int i = Name.length(); i < 15; i++) cout<<' ' ; 

        cout << accountNumber;
        int accountNumberLength = to_string(accountNumber).length();
        for (int i = accountNumberLength; i < 15; i++) cout << ' ';

        cout << balanceAmount << endl;
    }

    
    int getAccountNumber()
     {
        return accountNumber;
    }
};

int main() {
    int MAX_ACCOUNTS = 5;
    BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display All Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (accountCount < MAX_ACCOUNTS) {
                    string name;
                    int x;
                    double balance;

                    cout << "\nEnter customer name: ";
                    cin.ignore(); 
                    getline(cin, name);
                    cout << "Enter account number: ";
                    cin >> x;
                    cout << "Enter initial balance: ";
                    cin >> balance;

                    accounts[accountCount] = BankAccount(name, x, balance);
                    accountCount++;
                    cout << "\nAccount created successfully.";
                } else {
                    cout << "\nMaximum account limit reached.";
                }
                break;
            }
            case 2: {
                int ac_no;
                cout << "\nEnter account number: ";
                cin >> ac_no;

                int flag = 0; 
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i].getAccountNumber() == ac_no) {
                        double depositAmount;
                        cout << "Enter amount to deposit: ";
                        cin >> depositAmount;
                        accounts[i].deposit(depositAmount);
                        flag = 1; 
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "\nAccount not found.";
                }
                break;
            }
            case 3: {
                int ac_no;
                cout << "\nEnter account number: ";
                cin >> ac_no;

                int flag = 0;
                for (int i = 0; i < accountCount; ++i) {
                    if (accounts[i].getAccountNumber() == ac_no) {
                        double withdrawAmount;
                        cout << "Enter amount to withdraw: ";
                        cin >> withdrawAmount;
                        accounts[i].withdraw(withdrawAmount);
                        flag = 1; 
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "\nAccount not found.";
                }
                break;
            }
            case 4: {
                cout << "\nName            Account Number    Balance\n";
                cout << "--------------- --------------- ---------------\n";
                for (int i = 0; i < accountCount; ++i) {
                    accounts[i].display();
                }
                break;
            }
            case 5:
                cout << "\nProgram finished.";
                break;
            default:
            cout << "\nInvalid choice. Please try again.";
        }
    } while (choice != 5);

    return 0;
}
