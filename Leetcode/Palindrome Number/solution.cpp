#include<climits>
/*
    Solution to the Palindrome number problem
    https://leetcode.com/problems/palindrome-number/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int backwards = reverse(x);
        if (backwards == x) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int reverse(int x) {
        int backwards = 0;
        
        while (x != 0) {
            int remainder = x % 10;
            
            if (backwards > INT_MAX/10 || backwards < INT_MIN/10) {
                return 0;
            }
            
            backwards = backwards * 10 + remainder;
            x /= 10;
        }
        return backwards;
    }
};