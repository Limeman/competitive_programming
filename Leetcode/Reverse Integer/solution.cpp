#include<climits>
/*
    Solution to the reverse integer problem
    https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
    int reverse(int x) {
        int ret_val = 0;
        while (x != 0) {
            if (ret_val > INT_MAX/10 || ret_val < INT_MIN/10) {
                return 0;
            }
            
            int remainder = x % 10;
            
            ret_val = ret_val * 10 + remainder;
            
            x /= 10;
        }
        return ret_val;
    }
};