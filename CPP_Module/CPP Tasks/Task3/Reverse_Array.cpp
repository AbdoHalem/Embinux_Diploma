#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void rev_arr(T arr[], int size){
    for(int i = size-1, j=0; (i >= size/2) || (i == j); i--,j++){
        std::swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    rev_arr(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i : arr){
        cout << i << endl;
    }
    return 0;
}