#include <iostream>

using namespace std;

void swap_fun(int *a, int *b){
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++){
        cout << "Enter number " << i << ": ";
        cin >> arr[i];
    }
    // Sortng loop
    for(int i = 0; i < 10-1; i++){
        bool swapped = false;
        for(int j = 0; j < 9-i; j++){
            if(arr[j] > arr[j+1]){
                swap_fun(&arr[j], &arr[j+1]); swapped = true;
            }
        }
        if(!swapped){break;}
    }

    cout << "Values after sorting are: " << endl;
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
