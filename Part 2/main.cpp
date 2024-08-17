#include "device.h"

int main(){
    int a;
    cout<<"Welcome to our _Refrigerator exhibition_"<<endl;
    cout<<"\n";
    Fridge lg("black","LG");
    lg.GetInformation();
    cout<<"Total  mass   of this fridge is : "<<lg.Totalmass()/1000<<" kg"<<endl;
    cout<<"Total surface of this fridge is : "<<lg.TotalSurface()/10'000<<" sq-m"<<endl;
    cout<<"Total volume  of this fridge is : "<<lg.TotalVolume()/1'000<<" litres"<<endl<<endl;
    cout<<"To familiarize more with our wonderful fridge, try to get some water and open its door.\n\n";
    
    lg.WaterDispenser();
    lg.OpenTheDoor();

    cout<<"                **********************************\n";
    cout<<"         now let's take a look at our side by side fridge: \n";
    SideBySide sam;
    sam.GetInformation();
    cout<<"Total  mass   of this fridge is : "<<sam.Totalmass()/1000<<" kg"<<endl;
    cout<<"Total surface of this fridge is : "<<sam.TotalSurface()/10'000<<" sq-m"<<endl;
    cout<<"Total volume  of this fridge is : "<<sam.TotalVolume()/1'000<<" litres"<<endl<<endl;
    cout<<"To familiarize more with our wonderful fridge, try to get some water and open its door.\n";

    sam.WaterDispenser();
    sam.OpenTheDoor();

    cin>>a;
}