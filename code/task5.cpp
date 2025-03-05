#include<iostream>
using namespace std;
class Device{
    bool status;
    int deviceID;
    public:
        Device(int id,bool status):deviceID(id),status(status){};
        void displayDetails(){
            cout<<"Device ID: "<<deviceID<<endl<<"Status: ";
            if(status){
                cout<<"Working";
            }
            else{
                cout<<"Not working";
            }
            cout<<endl;
        }
};
class SmartPhone: virtual public Device{
    public:
        float screenSize;
        SmartPhone(int id,bool status,float size):Device(id,status),screenSize(size){};
        void displayDetails(){
            Device::displayDetails();
            cout<<"Screen Size: "<<screenSize<<endl;
        }
};
class SmartWatch: virtual public Device{
    public:
        bool heartRateMonitor;
        SmartWatch(int id,bool status,bool rate):Device(id,status),heartRateMonitor(rate){}
        void displayDetails(){
            Device::displayDetails();
            cout<<"Heart Rate Monitor: ";            
            if(heartRateMonitor){
                cout<<"Working";
            }
            else{
                cout<<"Not working";
            }
            cout<<endl;    
        }
};
class SmartWearable: public SmartPhone,public SmartWatch{
    int stepCounter;
    public:
        SmartWearable(int id,bool status,bool rate,int counter,float size):Device(id,status),SmartPhone(id,status,size),SmartWatch(id,status,rate),stepCounter(counter){}
        void displayDetails(){
            Device::displayDetails();    
            cout<<"Screen Size: "<<screenSize<<endl;
            cout<<"Heart Rate Monitor: ";
            if(heartRateMonitor){
                cout<<"Working";
            }
            else{
                cout<<"Not working";
            }
            cout<<endl;
            cout<<"stepCounter: "<<stepCounter<<endl;
        }
};
int main(){
    int id,counter,isWorking;
    float size;
    bool heartRateMonitor,status;
    cout<<"Inputing the details of a smart wearable"<<endl;
    cout<<"Enter device id: ";
    cin>>id;
    cout<<"What is the status of the device (Enter 0 for not working otherwise any number for working): ";
    cin>>isWorking;
    if(isWorking==0){
        status=0;
    }
    else{
        status=1;
    }
    cout<<"Enter screen size: ";
    cin>>size;
    cout<<"How is the heart rate monitor of the device (Enter 0 for not working otherwise any number for working): ";
    cin>>isWorking;
    if(isWorking==0){
        heartRateMonitor=0;
    }
    else{
        heartRateMonitor=1;
    }
    cout<<"Enter number of step counter: ";
    cin>>counter;
    SmartWearable wearable(id,status,heartRateMonitor,counter,size);
    cout<<endl<<"Displaying smart wearable's details"<<endl;
    wearable.displayDetails();
    return 0;
}