#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isValid(string s) {
    bool correct = true;
    std::vector<char> vec;
    for(char ch : s){
        if(ch == '{'){vec.push_back('}'); continue;}
        else if (ch == '('){vec.push_back(')'); continue;}
        else if (ch == '['){vec.push_back(']'); continue;}
        // Search for closing parenthesis
        if((vec.size()!= 0) && (ch == vec[vec.size()-1])){vec.pop_back();}
        else{correct = false; return correct;}
    }
    if(vec.size() != 0){correct = false;}
    return correct;
}

int main()
{
    std::string str = ")";
    cout << isValid(str) << endl;
    return 0;
}