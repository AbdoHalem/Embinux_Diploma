#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void rot_arr(T arr[], int size, int iterations){
    for(int iter = 0; iter < iterations; iter++){
        for(int i = 0; i < size-1; i++){
        arr[i] += arr[i+1];     // a = a + b
        arr[i+1] = arr[i] - arr[i+1];   // b = (a+b) - b = a
        arr[i] = arr[i] - arr[i+1];     // a = (a+b) - (a) = b
        }
    }
}

int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++){
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Enter number of rotations: ";
    int iter = 0;
    cin >> iter;
    rot_arr(arr, sizeof(arr)/sizeof(arr[0]), iter);
    for(int i : arr){
        cout << i << endl;
    }
    return 0;
}