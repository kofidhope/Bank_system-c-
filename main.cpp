#include <iostream>

using namespace std;

class BankAccount{
private:
    string accountNumber;
    string accountHolderName;
    double accountBalance;

public:
    BankAccount(string number,string name,double balance){
        accountNumber=number;
        accountHolderName=name;
        accountBalance=balance;
    }

    void deposit(double amount){
        accountBalance +=amount;
        cout <<"Amount deposited successfully.New balance:$" << accountBalance <<endl;

    }

    void withdraw(double amount){
        if(amount<=accountBalance){
            accountBalance-=amount;
            cout << "Amount withdrawn successfully.New balance:$" << accountBalance <<endl;
        }else{
            cout <<"Insufficient funds."<<endl;
        }
    }

    void checkBalance(){
        cout << "AccountHolder:" << accountHolderName<<endl;
        cout << "Account Number:"<< accountNumber << endl;
        cout << "Balance: $"<< accountBalance << endl;
    }
};


int main()
{
    string accountNumber,accountHolderName;
    double initialBalance;

    cout << "Welcome to the Bank System" << endl;
    cout << "Please enter your account number" <<endl;
    cin >> accountNumber;
    cout << "Please account holder name: ";
    cin.ignore();
    getline(cin,accountHolderName);
    cout << "Please enter your initial balance:$ ";
    cin>>initialBalance;

    BankAccount account(accountNumber,accountHolderName,initialBalance);

    int choice;
    double amount;
    bool exit = false;

    while(!exit){
        cout << "\nBank Operations" << endl;
        cout << "1.Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3.Check Balance" << endl;
        cout << "4.Exit" << endl;

        cout << "Select an Operation: ";
        cin >>choice;

        switch(choice){
        case 1:
            cout << "Enter the amount to deposit" << endl;
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw:$ ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.checkBalance();
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    cout << "Thank you for using our Bank System" << endl;

    return 0;
}
