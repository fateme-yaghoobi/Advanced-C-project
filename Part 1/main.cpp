#include "Vector.h"
#include "vector_pointer.h"

class Shape{
    //data members
   int *data=new int[100'000'000];

    public:
    // Shape(){
    //     for (int i=0;i<100;i++)data[i]=0;
    // }
};

int main(){
    
    cout<<"***Using previous vector***\n";
    Vector shapes(300, Shape());

    // Measure insert time
        clock_t start = clock();
        for (int i=0;i<5;i++){
            srand(i);
            shapes.Insert(rand()%300);
        }
        clock_t end = clock();
        cout << "Insert time duration: " << (end - start) << " clocks" <<endl;


    // Measure remove time
        start = clock();
        for (int i=45;i<50;i++){
            srand(i);
            shapes.Remove(rand()%300);
        }
        end = clock();
        cout << "remove time duration: " << (end - start) << " clocks" <<endl;


    cout<<"***Using vector pointer instead***\n";
    myspace::vector shapes2(300, Shape());

        // Measure insert time
       start = clock();
        for (int i=0;i<5;i++){
            srand(i);
            shapes2.Insert(rand()%300);
        }
        end = clock();
        cout << "Insert time duration: " << (end - start) << " clocks" <<endl;


    // Measure remove time
        start = clock();
        for (int i=45;i<50;i++){
            srand(i);
            shapes2.Remove(rand()%300);
        }
        end = clock();
        cout << "remove time duration: " << (end - start) << " clocks" <<endl;
}