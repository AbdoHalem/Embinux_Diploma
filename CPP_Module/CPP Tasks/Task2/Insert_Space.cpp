// Write a C++ code to insert a space whenever a lower character 
// followed by upper character in a string
#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    string str;
    cout << "Enter a string : ";
    cin >> str ;
    for(unsigned int i = 1; i < str.length(); i++){
        if(isupper(str[i])){
            str.insert(i++, " ");   // increment i to avoid infinite loop
        }
    }
    cout << str << endl;
    return 0;
}
