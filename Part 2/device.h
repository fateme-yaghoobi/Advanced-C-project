#include <iostream>
#include <string>
using namespace std;

//Shape class
class Shapes{
    protected:
    double density;//grams per square centimeter

    public:
    Shapes(double _density=double ()){density=_density;}


    virtual double EvalVolume(){return 0.0;}
    virtual double EvalMass(){return 0.0;}
    virtual double EvalSurface(){return 0.0;}

    ~Shapes(){
        // cout<<"destructor was run!\n";
    }

};

//Box class
class Box:public Shapes{
protected:
    double width;//centimeter
    double length;//centimeter
    double height;//centimeter

public:
    Box(double _density=0.9,double _width=74.0,double _length=74.0,double _height=30.0)
        :Shapes(_density),width(_width),length(_length),height(_height){}
        
    double EvalVolume()override{return width*length*height;}
    double EvalMass()override{return (2*0.7*length*height+2*0.7*width*height+0.7*length*width)*density;}
    double EvalSurface()override{return 2*width*length + 2*length*height + 2*width*height;}
};

//Cylinder class
class Cylinder:public Shapes{
    protected:
    double radius;//centimeter
    double height ; //centimeter  

    public:
    Cylinder(double _density=double (),double _radius=0.0,double _height=0.0):Shapes(_density) ,radius(_radius),height(_height){density=_density;}
    double EvalVolume()override{return radius*height;}
    double EvalMass()override{return EvalVolume()*density;}
    double EvalSurface()override{return 2*3.14159265*radius*height;}
};

//Handle class
class Handle:public Cylinder{
    public:
    Handle(double _density=0.941,double _radius=1.0,double _height=100)
        :Cylinder(_density,_radius,_height){}

        void PullOrPush(){
            unsigned int a;
            cout<<"do you wanna close or open the fridge ?\n     press 1 to open, \n     press 0 to close it : ";
            cin>>a;
            switch(a){
                case 0:
                    cout<<"door closed, light off!\n";
                    break;
                case 1:
                    cout<<"door opend, light on!\n";
                    break;
                default:
                    cout << "Invalid input!\n" << endl;
            }
        }



};

//WaterTank class
class WaterTank:public Box{
    public:
    int a{0};
        WaterTank(double _density=0.941,double _width=13.2,double _length=73.0,double _height=9.3)
                :Box(_density, _width, _length, _height) {}

        void FillTheWaterTank(){
                a=1000;
        }
        void PullOrPush(){
            unsigned int b{0},c{0};
            cout<<"If you wanna get 100cc water press 1, or else press any key.\n";
            cin>>b;

            if (b==1)
            {
                if (a>=100){
                    cout<<"enjoy your water!\n";
                    a-=100;
            }
                else if (a<100){
                    cout<<"no enough water in the tank, press 1 to fill it\n";
                    cin>>c;
                    if (c==1){
                        FillTheWaterTank();
                        PullOrPush();}
            }  
            }
        }
};

//Fridge class as Device, single door fridge
class Fridge:public Box{
protected:
    int price = 15'290;
    
    public:
    Handle handle = Handle(0.941,1.0,100);
    WaterTank watertank = WaterTank(0.941,13.2,73.0,9.3);

    Box box1;//first from top
    Box box2;//second from top
    Box box3;//third from top
    Box box4;//Fourth from top
    Box box5 = Box(0.9, 74.0, 37.0, 30.0);//bottem
    Box box6 = Box(0.9, 74.0, 37.0, 30.0);//bottem

    string color;
    string brand;
    //Fridges constructor
    Fridge(string _color="white",string _brand="Samsung")
        :Box(2, 75.0, 75.0, 175.0),color(_color),brand(_brand){}

    virtual void OpenTheDoor(){
        handle.PullOrPush();
    }
    
    void WaterDispenser(){
        watertank.PullOrPush();
    }
        
    double TotalVolume(){  
        double temp=EvalVolume()+handle.EvalVolume();
        return temp;
    }
    
    double Totalmass(){
        double temp=EvalMass() + 0.7*length*height*density+ box1.EvalMass()*4 + box5.EvalMass()*2 + handle.EvalMass();
        return temp;
    }
   
    double TotalSurface () {
        double temp=EvalSurface()+handle.EvalSurface();
        return temp;
    }

   virtual void GetInformation(){
        cout<<"--> This single door, "<< color <<" "<< brand <<" fridge "<<"costs "<<price<<"  $\n";
        cout<<"      it's got a water dispenser and 6 boxes to contain food in it.\n";
    }

    
};

//Side by Side Fridge
class SideBySide:public Fridge{
public:
    Handle handle2 = Handle (0.941,1.0,100);
    Box box7= Box (0.9,74.0,74.0,58.0);
    Box box8 = Box (0.9,74.0,74.0,57.0);
    Box box9 = Box (0.9,74.0,74.0,58.0);


    SideBySide(string _color="white",string _brand="Samsung"): Fridge(_color, _brand)
        {
            density=2;
            width=75.0;
            length=150.0;
            height=175.0;  
            price= 69'990;       
        }

    void OpenTheDoor()override{
        unsigned int h;
        cout<<"Choose a door:\n     press 1 for right one,\n     press 2 for left one : ";
        cin>>h;
        switch(h){
            case 1:
                handle.PullOrPush();
                break;
            case 2 :
                handle2.PullOrPush();
                break;
            default:
                cout << "Invalid input!\n" << endl;
        }    
    }
    virtual void GetInformation(){
        cout<<"--> This side by side , "<< color <<" "<< brand <<" fridge "<<"costs "<<price<<" $\n";
        cout<<"      it's got a water dispenser and 6 food boxes in left side\n      and 3 boxes for frazer in the right side.\n";
    }
};
