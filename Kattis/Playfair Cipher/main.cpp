#include<iostream>
#include<string>
#include<utility>
#include<map>

std::string encrypt_pair(std::string &str,std::map<char, std::pair<int, int>> &index, char (&table)[5][5]) {
    std::pair<int, int> left = index[str[0]];
    std::pair<int, int> right = index[str[1]];

    std::string ret_val = "";
    if (left.second == right.second) {
        int i = (left.first + 1 > 4 ? 0 : left.first + 1);
        int j = (right.first + 1 > 4 ? 0 : right.first + 1);
        ret_val += toupper(table[i][left.second]);
        ret_val += toupper(table[j][right.second]);
        return ret_val;
    }
    else if (left.first == right.first) {
        int i = (left.second + 1 > 4 ? 0 : left.second + 1);
        int j = (right.second + 1 > 4 ? 0 : right.second + 1);
        ret_val += toupper(table[left.first][i]);
        ret_val += toupper(table[right.first][j]);
        return ret_val;
    }
    else {
        ret_val += toupper(table[right.first][left.second]);
        ret_val += toupper(table[left.first][right.second]);
        return ret_val;
    }
}

int main() {
    char table[5][5];
    std::map<char, bool> added;
    std::map<char, std::pair<int, int>> index;
    std::string key, message;
    std::getline(std::cin, key);
    std::getline(std::cin, message);
    int i = 0;
    for (auto k : key) {
        if (k == ' ') {
            continue;
        }
        if (added.find(k) == added.end()) {
            table[i % 5][i / 5] = k;
            added[k] = 1;
            index[k] = std::pair<int, int>(i % 5, i / 5);
            ++i;
        }
    }
    // Alphabet without q
    std::string alphabet = "abcdefghijklmnoprstuvwxyz";
    for (auto a : alphabet) {
        if (added.find(a) == added.end()) {
            table[i % 5][i / 5] = a;
            index[a] = std::pair<int, int>(i % 5, i / 5);
            ++i;
        }
    }

    i = 0;
    std::string ret_val;
    int j = 1;
    while (j < message.length()) {
        if (message[i] == ' ') {
            ++i;
            ++j;
            continue;
        }
        if (message[j] == ' ') {
            ++j;
            continue;
        }

        if (message[i] == message[j]) {
            std::string pair = "";
            pair += message[i];
            pair += "x";
            ret_val += encrypt_pair(pair, index, table);
            i = j;
            ++j;
        }
        else {
            std::string pair = "";
            pair += message[i];
            pair += message[j];
            ret_val += encrypt_pair(pair, index, table);
            i = j + 1;
            j += 2;
        }
    }

    if (i == message.length() - 1) {
        std::string pair = "";
        pair += message[i];
        pair += "x";
        ret_val += encrypt_pair(pair, index, table);
    }

    std::cout << ret_val << std::endl;
    return 0;
}