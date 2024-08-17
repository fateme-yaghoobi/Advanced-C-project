#include<iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#define BigNumber 100'000'000
using namespace std;
/*Vector must contain data members like:
    N:size
    default
and also contain some member functions like:
    size
    resize
    pushpack
    #new:
        insert(int i) --> inserts an element at "i"
        remove(int i) --> removes an element at "i"
and a operator->[] : to access the indicated index
*/

template <typename T>
class Vector{

    //data members
    int N;//size of the arraye
    T Default;
    
public:
    
    T* data=new T [N];
    //constructor
    explicit Vector (int _N=0, T _Default=T()):N(_N),Default(_Default){    
        for(int i=0;i<N;i++){
        data[i]=Default;
        }
    }
    

    //desconstructor
    ~Vector(){
        delete[] data;
    }

    //[] operator = .at()
    T& operator[](int i){
        return data[i];

    }

    //resize function
    void Resize(int a,T NewDefault=T()){
        if(a>N){
            T* Expanded_Data=new T[a];

            for (int i=0;i<N;i++){
                Expanded_Data[i]=data[i];
            }

            for(int i=N;i<a;i++){// 0 1 2 3 4    5 6 7 8 9
                Expanded_Data[i]=NewDefault;
            }

            delete[] data;
            data=Expanded_Data;
            N=a;
        }
        else {
            T* Contracted_Data=new T[a];
            int TheDiffrence=N-a;
            for (int i=0;i<TheDiffrence;i++){
                Contracted_Data[i]=data[i];
            }

            delete[] data;
            data=Contracted_Data;
            N=a;
        }
    }

    //pushback function
    void Pushback(T b){
        T* Modified_data=new T[N+1];
        for (int i=0;i<N;i++){
            Modified_data[i]=data[i];
        }
        Modified_data[N]=b;
        
        delete[] data;
        data=Modified_data;
        N++;
    }

    //size() function
    int Size(){
        return N;
    }


    //insert function
    void Insert(int i, T Value=T()){
        N++;
        T *Modified_data= new T [N];
        for (int j=0;j<i;j++){
            Modified_data[j]=data[j];
        }
        Modified_data[i]=Value;
        for(int j=i+1;j<N;j++){
            Modified_data[j]=data[j-1];
        }

        delete[] data;
        data=Modified_data;
    }

    //remove function
    void Remove(int i){
        N--;
        T *Modified_Data=new T [N];
        for (int j=0;j<i;j++){
            Modified_Data[j]=data[j];
        }
        for (int j=i;j<N;j++){
            Modified_Data[j]=data[j+1];

        }

        delete[] data;
        data=Modified_Data;
    }
};