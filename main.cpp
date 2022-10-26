#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class ord{

public:

    static void Read(int vector[]){
        ifstream arch;


        arch.open("BigList.txt",ios::in);

        if(arch.fail()){
            cout << "no valio jaj";
            exit(1);
        }

        int i=0;

        while(!arch.eof()){
            arch >> vector[i];
            i++;
        }

        arch.close();



    };

    static int partition(int arr[], int start, int end)
    {

        int pivot = arr[start];

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);

        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i] <= pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
    }

    void quickSort(int arr[], int start, int end)
    {


        if (start >= end)
            return;

        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);

        quickSort(arr, p + 1, end);
    }

    void printVector(int vector[], int size){

        cout << "{";

        for (int i = 0 ; i < size ; ++i) {

            cout << vector[i] << " ";

        }

        cout <<"}\n";
    }


};

int main() {
    auto start = high_resolution_clock::now();

    srand(time(NULL));

    ord XD;

    //Cambiar el tamaño de la lista y la variable SZ xd 

    //take user input. 
    // SABIAS QUE  "Pikachu está inspirado en una ardilla?" QUE LOCO...
    int UserInput;
    cout << "Cuantos datos deseas leer?: "; 
    cin >> UserInput; 
    cout << "Your number is: " << UserInput;
    
    int list[UserInput];

    XD.Read(list);

    int SZ=UserInput;

    XD.printVector(list,SZ);

    XD.quickSort(list,0,SZ-1);

    cout << "Ordenado:\n";

    XD.printVector(list,SZ);

    auto stop = high_resolution_clock::now();



    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;



    return 0;
}
