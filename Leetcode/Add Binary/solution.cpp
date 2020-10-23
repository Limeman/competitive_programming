#include<string>
/*
    Solution to the Add Binary problem
    https://leetcode.com/problems/add-binary/
*/

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        bool A, B, AB, sum, carry = 0;
        std::string ret_val = "";
        int i = a.length() - 1, j = b.length() - 1;
        
        // Full adder
        while (i >= 0 && j >= 0) {
            A = a[i] == '1';
            B = b[j] == '1';
            
            AB = A ^ B;
            sum = AB ^ carry;
            carry = (AB & carry) | (A & B);
            
            ret_val = (sum ? "1" : "0") + ret_val;
            
            --i;
            --j;
        }
        
        // Half adder
        while (i >= 0) {
            A = a[i] == '1';
            
            sum = A ^ carry;
            carry = A & carry;
            
            ret_val = (sum ? "1" : "0") + ret_val;
            
            --i;
        }
        
        // Half adder
        while (j >= 0) {
            B = b[j] == '1';
            
            sum = B ^ carry;
            carry = B & carry;
            
            ret_val = (sum ? "1" : "0") + ret_val;
            
            --j;
        }
        
        // Final carry
        ret_val = (carry ? "1" : "") + ret_val;
        
        return ret_val;
    }
    
};