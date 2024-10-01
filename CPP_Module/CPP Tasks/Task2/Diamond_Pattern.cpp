#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 0;
    cout << "Please enter the number of rows(half of the diamond): " << endl;
    cin >> num;
    string first = " ", middle = "*", last = "*";
    // Print the upper half of the pattern
    for(int i = 1; i <= num; i++){
        first = string(abs(num - i), ' ');    // Generate a string of spaces
        middle = string(i, '*');               // Generate a string of asterisks
        last = string(i - 1, '*');             // Generate another string of asterisks
        cout << first + middle + last << endl;
    }
    // Print the lower half of the pattern
    for(int i = num-1; i > 0; i--){
        first = string(abs(num - i), ' ');    // Generate a string of spaces
        middle = string(i, '*');               // Generate a string of asterisks
        last = string(i - 1, '*');             // Generate another string of asterisks
        cout << first + middle + last << endl;
    }
    return 0;
}

