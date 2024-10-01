#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // counter represents the number of digits
        long long  i = 1;
        int counter = 0;
        int temp_x = x;
        int left = 0;       // represents x when it is mirrored (e.g x = 1234 => left 4321)
        if(x == 0){
            return true;
        }
        while (temp_x != 0)
        {
            temp_x /= 10; counter++;        // Calculate number of digits of x
        }
        int divider = pow(10, counter-1);
        char modulus = 0;

        while(divider != 0){
            modulus = (x / divider) % 10;
            divider /= 10;
            left += modulus * i;
            i *= 10;
        }
        if(left == x && x > 0){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){
    int x = 0;
    cin >> x;
    Solution obj;
    bool res = obj.isPalindrome(x);
    if(res){
        printf("%d is a palindrome\n", x);
    }
    else{
        printf("%d is not a palindrome\n", x);
    }
    
    return 0;
}