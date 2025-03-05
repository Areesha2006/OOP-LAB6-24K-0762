#include<iostream>
using namespace std;
class Account{
    int accountNumber;
    float balance;
    public:
        Account(int acc_no,float balance):accountNumber(acc_no),balance(balance){}
        void displayDetails(){
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};
class SavingsAccount: public Account{
    float interestRate;
    public:
        SavingsAccount(int acc_no,float balance,float interest):Account(acc_no,balance),interestRate(interest){}
        void displayDetails(){
            Account::displayDetails();
            cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
        }
};
class CheckingAccount: public Account{
    float overdraftLimit;
    public:
        CheckingAccount(int acc_no,float balance,float limit):Account(acc_no,balance),overdraftLimit(limit){}
        void displayDetails(){
            Account::displayDetails();
            cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
        }
};
int main(){
    int acc_no;
    float balance,rate,limit;
    cout<<"Enter details for saving account"<<endl;
    cout<<"Enter account number: ";
    cin>>acc_no;
    cout<<"Enter balance: ";
    cin>>balance;
    cout<<"Enter interest rate: ";
    cin>>rate;
    SavingsAccount sav_acc(acc_no,balance,rate);
    cout<<endl<<"Ente details for checking account"<<endl;
    cout<<"Enter account number: ";
    cin>>acc_no;
    cout<<"Enter balance: ";
    cin>>balance;
    cout<<"Enter overdraft limit: ";
    cin>>limit;
    CheckingAccount check_acc(acc_no,balance,limit);
    cout<<endl<<"Displaying the details of saving account"<<endl;
    sav_acc.displayDetails();
    cout<<endl<<"Displaying the details of checking account"<<endl;
    check_acc.displayDetails();
    return 0;
}