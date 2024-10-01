#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int calc_max(int numbers[], int size){
    int max = numbers[0];
    for(int i = 1; i < size; i++){
        if(numbers[i] >= max){max = numbers[i];}
    }
    return max;
}

int main() {
    int numbers[5];
    cout << "Enter 5 numbers: " << endl;
    for(int i = 0; i < 5; i++){
        cin >> numbers[i];
    }
    int max = calc_max(numbers, sizeof(numbers)/sizeof(int));
    cout << "The maximum number = " << max << endl;
    return 0;
}
