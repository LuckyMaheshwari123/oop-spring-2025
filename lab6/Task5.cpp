#include<iostream>
using namespace std;
class Device{
  protected:
  int deviceid;
  bool status;
  public:
  Device(int deviceid,bool status):deviceid(deviceid),status(status){
  }
  
  void display(){
    cout<<"ID: "<<deviceid<<endl;
    cout<<"Status:"<<status<<endl;
  }
};

class smartPhone: public Device{
  protected:
  float screenSize;
  public:
  smartPhone(int deviceid,bool status,float screenSize):Device(deviceid,status),screenSize(screenSize){}
  
  void display(){
    Device::display();
    cout<<"Screen Size: "<<screenSize<<endl;
  }
};

class smartWatch:public Device{
  protected:
  bool heartRate;
  public:
  smartWatch(int deviceid,bool status,bool heartRate):Device(deviceid,status),heartRate(heartRate){}
  
  void display(){
 //   Device::display();
   cout<<"heartRate: "<<heartRate<<endl;
  }
};

class smartWear:
public smartPhone,public smartWatch{
  protected:
  int stepCounter;
  public:
  smartWear(int deviceid,bool status,float screenSize,bool heartRate,int stepCounter):smartPhone(deviceid,status, screenSize),smartWatch(deviceid,status,heartRate),stepCounter(stepCounter){}
  
  void display(){
    smartPhone::display();
 smartWatch::display();
    cout<<"stepcounter: "<<stepCounter<<endl;
  }
};


int main(){
  smartWear s1(12,true,12.7,true,15);
  s1.display();
  return 0;     
}	
