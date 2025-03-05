#include<iostream>
using namespace std;
class Vehicle{
    string brand;
    int speed;
    public:
        Vehicle(string brand,int speed):brand(brand),speed(speed){}
        void displayDetails(){
            cout<<"Brand: "<<brand<<endl<<"Speed: "<<speed<<endl;
        }
};
class Car: public Vehicle{
    int seats;
    public:
        Car(string brand,int speed,int seats):Vehicle(brand,speed),seats(seats){}
        void displayDetails(){
            Vehicle::displayDetails();
            cout<<"Seats: "<<seats<<endl;
        }
};
class ElectricCar: public Car{
    int batteryLife;
    public:
        ElectricCar(string brand,int speed,int seats,int life):Car(brand,speed,seats),batteryLife(life){}
        void displayDetails(){
            Car::displayDetails();
            cout<<"Battery life: "<<batteryLife;
        }
};
int main(){
    string brand;
    int speed,seats,battery;
    cout<<"Inputing the details of an electric car"<<endl;
    cout<<"Enter brand: ";
    cin>>brand;
    cout<<"Enter speed: ";
    cin>>speed;
    cout<<"Enter seats: ";
    cin>>seats;
    cout<<"Enter battery life: ";
    cin>>battery;
    ElectricCar e(brand,speed,seats,battery);
    cout<<endl<<"Displaying electric car's details"<<endl;
    e.displayDetails();
    return 0;
}