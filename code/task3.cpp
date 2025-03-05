#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
    public:
        Person(string name,int a):name(name),age(a){};
        void displayDetails(){
            cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
        }
};
class Teacher: virtual public Person{
    public:
        string subject;
        Teacher(string name,int a,string sub):Person(name,a),subject(sub){};
        void displayDetails(){
            Person::displayDetails();
            cout<<"Subject: "<<subject<<endl;
        }
};
class Researcher: virtual public Person{
    public:
        string researchArea;
        Researcher(string name,int a,string area):Person(name,a),researchArea(area){}
        void displayDetails(){
            Person::displayDetails();
            cout<<"Research Area: "<<researchArea<<endl;
        }
};
class Professor: public Teacher,public Researcher{
    int publications;
    public:
        Professor(string name,int a,string sub,string area,int pub):Person(name,a),Teacher(name,a,sub),Researcher(name,a,area),publications(pub){}
        void displayDetails(){
            Person::displayDetails();    
            cout<<"Subject: "<<subject<<endl;
            cout<<"Research Area: "<<researchArea<<endl;
            cout<<"Publications: "<<publications<<endl;
        }
};
int main(){
    int pub,age;
    string name,sub,area;
    cout<<"Inputing the details of a professor"<<endl;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter age: ";
    cin>>age;
    cout<<"Enter subject: ";
    cin>>sub;
    cout<<"Enter reasearch area: ";
    cin>>area;
    cout<<"Enter number of publications: ";
    cin>>pub;
    Professor prof(name,age,sub,area,pub);
    cout<<endl<<"Displaying professor's details"<<endl;
    prof.displayDetails();
    return 0;
}