#include <iostream>
#include <string>
#include <limits>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    long long accountNumber;
    double balance;

public:
    void createAccount()
    {
        cout << "Enter account holder name: ";
        getline(cin, accountHolderName);

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter initial balance: Rs. ";
        cin >> balance;

        while (balance < 0)
        {
            cout << "Initial balance cannot be negative. Enter again: Rs. ";
            cin >> balance;
        }

        cout << "\nAccount created successfully!\n";
    }

    void deposit()
    {
        double amount;

        cout << "Enter deposit amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount. Deposit must be greater than zero.\n";
            return;
        }

        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void withdraw()
    {
        double amount;

        cout << "Enter withdrawal amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount. Withdrawal must be greater than zero.\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance.\n";
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void displayBalance() const
    {
        cout << "\n----- Account Details -----\n";
        cout << "Account holder : " << accountHolderName << '\n';
        cout << "Account number : " << accountNumber << '\n';
        cout << "Balance        : Rs. " << balance << '\n';
    }
};

int main()
{
    BankAccount account;
    int choice;

    cout << "===== BANK MANAGEMENT SYSTEM =====\n";
    account.createAccount();

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display account balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            account.deposit();
            break;

        case 2:
            account.withdraw();
            break;

        case 3:
            account.displayBalance();
            break;

        case 4:
            cout << "Thank you for using the Bank Management System!\n";
            break;

        default:
            cout << "Invalid choice. Please select 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
