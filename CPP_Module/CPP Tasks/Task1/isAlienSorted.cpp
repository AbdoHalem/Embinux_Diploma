#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        auto getCharIndex = [&order](char c) {
            return order.find(c);
        };
        for(unsigned int i = 0; i < words.size() - 1; i++){
            string string1 = words[i], string2 = words[i+1];
            unsigned char str_size = string1.size() < string2.size() ? string1.size() : string2.size();
            bool equality = true;

            for(unsigned int j = 0; j < str_size; j++){
                // get the order of char in string1 and char in string2
                char char1_index = getCharIndex(string1[j]);
                char char2_index = getCharIndex(string2[j]);
                // Check their order
                if(char1_index > char2_index){return false;}
                else if (char1_index < char2_index){equality = false; break;}
                else{equality = true;}
            }
            // Check of length of string1 if it is more than length of string2
            if ((string1.size() > string2.size()) && equality){return false;}
        }
        return true;
    }
};

int main() {
    string order = "ngxlkthsjuoqcpavbfdermiywz";
    vector<string> words = {"kuvp","q"};
    Solution obj;
    bool res = obj.isAlienSorted(words, order);
    if(res){
        cout << " is sorted" << endl;
    } else {
        cout << " is not sorted" << endl;
    }

    return 0;
}
