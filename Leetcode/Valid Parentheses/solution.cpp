#include<stack>
#include<string>
/*
    Solution to the Valid Parentheses problem
    https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
    std::stack<char> history;
public:
    bool isValid(std::string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (is_opener(s[i])) {
                history.push(s[i]);
            }
            else {
                if (this->history.empty()) {
                    return false;
                }
                if (s[i] == ')' && this->history.top() == '(' || s[i] == ']' && this->history.top() == '[' || s[i] == '}' && this->history.top() == '{') {
                    history.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (this->history.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool is_closer(char c) {
        return !is_opener(c);
    }
    bool is_opener(char c) {
        if (c == '(' || c == '[' || c == '{') {
            return true;
        }
        else {
            return false;
        }
    }
    /*
    // Old overly-engineered solution
    
    bool evaluate(std::string s, int pos) {
        if (valid_char(s[pos])) {
            if (pos == s.length() - 1 && correct_closer(s[pos]) && this->history.size() == 1) {
                return true;
            }
            else {
                if (is_closer(s[pos])) {
                    this->history.pop();
                }
                else {
                    this->history.push(s[pos]);
                }
                return this->evaluate(s, ++pos);
            }
        }
        else {
            return false;
        }
    }
    
    bool valid_char(char c) {
        if (this->is_opener(c)) {
            return true;
        }
        else if (this->history.size() == 0) {
            return false;
        }
        else if (this->correct_closer(c)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool correct_closer(char c) {
        if (c == ']' && this->history.top() == '[') {
            return true;
        }
        if (c == ')' && this->history.top() == '(') {
            return true;
        }
        if (c == '}' && this->history.top() == '{') {
            return true;
        }
        return false;
    }
    
    bool is_closer(char c) {
        if (!this->is_opener(c)) {
            return true;
        }
        else {
            return false;
        }
    }
    bool is_opener(char c) {
        if (c == '(' || c == '[' || c == '{') {
            return true;
        }
        else {
            return false;
        }
    }*/
};