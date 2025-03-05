#include<iostream>
using namespace std;
class Employee{
    public:
        string name;
        float salary;
        Employee(string name,float sal):name(name),salary(sal){}
        void displayDetails(){
            cout<<"Name: "<<name<<endl<<"Salary: "<<salary<<endl;
        }
};
class Manager: public Employee{
    float bonus;
    public:
        Manager(string name,float sal,float b):Employee(name,sal),bonus(b){}
        void displayDetails(){
           Employee::displayDetails();
           cout<<"bonus: "<<bonus<<endl;
        }
};
int main(){
    string name;
    float salary;
    float bonus;
    cout<<"Inputing the details of the manager"<<endl;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter salary: ";
    cin>>salary;
    cout<<"Enter bonus: ";
    cin>>bonus;
    Manager m(name,salary,bonus);
    cout<<endl<<"Displaying manager's details"<<endl;
    m.displayDetails();
    return 0;
}