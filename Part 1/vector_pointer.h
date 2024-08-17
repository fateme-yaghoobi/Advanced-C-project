#include <iostream>

namespace myspace {
template <typename T>
class vector{
     public:
	vector(){}
	vector(int _N, T _Val);
	~vector();
    T Resize(int a,T NewDefault=T());
	T operator[] (int i);
    T Pushback(T b);
	T Insert(int i, T Value=T());
	T Remove(int i);
	int size(){
		return N;
	}
		;
     protected:
        T** data;	
	int N;	
};


template <typename T>
vector<T>::vector(int _N, T _Val ):N(_N){
    data = new T*[N];
    for (int i{0}; i < N; i++){
	    data[i] = new T(_Val);
    }
}

template <typename T>
vector<T>::~vector(){
	for (int i{0};i < N; i++){
		delete data[i];
	}
	delete [] data;
}

template <typename T>
T vector<T>::operator[] (int i){
	try {
		if (i>=0 && i < N){
			return *data[i];
		}
		else
		 throw(i);
	}
		catch(int i){
			std::cout << "out of range, try to access "<< i << " out of " << N <<"\n";
			exit(-1);
		}
}

template <typename T>
	T vector<T>::Pushback(T b){
        T** Modified_data=new T* [N+1];
        for (int i=0;i<N;i++){
            Modified_data[i]=data[i];
        }
        Modified_data[N]=new T(b);

		delete [] data;
        data=Modified_data;
        N++;
    }

template <typename T>
T vector<T>::Resize(int a,T NewDefault){
        if(a>N){
            T** Expanded_Data=new T* [a];

            for (int i=0;i<N;i++){
                Expanded_Data[i]=data[i];
            }

            for(int i=N;i<a;i++){// 0 1 2 3 4    5 6 7 8 9
                Expanded_Data[i]=NewDefault;
            }

		delete [] data;
            data=Expanded_Data;
            N=a;
        }
        else {
            T** Contracted_Data=new T* [a];
            int TheDiffrence=N-a;
            for (int i=0;i<TheDiffrence;i++){
                Contracted_Data[i]=data[i];
            }

		delete [] data;
            data=Contracted_Data;
            N=a;
        }
    }

	template <typename T>
	T vector<T>::Insert(int i, T Value){
        N++;
        T** Modified_data= new T* [N];
        for (int j=0;j<i;j++){
            Modified_data[j]=data[j];
        }
        Modified_data[i]=new T (Value);
        for(int j=i+1;j<N;j++){
            Modified_data[j]=data[j-1];
        }

		delete [] data;
        data=Modified_data;

        return T();
    }

	template <typename T>
	T vector<T>::Remove(int i){
        N--;
        T** Modified_Data=new T* [N];
        for (int j=0;j<i;j++){
            Modified_Data[j]=data[j];
        }
        for (int j=i;j<N;j++){
            Modified_Data[j]=data[j+1];

        }

        delete [] data;
        data=Modified_Data;

        return T();       
    }

	
/// end of namespace ///
}