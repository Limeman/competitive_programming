#include<algorithm>
#include<iostream>
#include<vector>


int main() {
    int n, curr;
    std::vector<int> busses;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> curr;
        busses.push_back(curr);
    }

    std::sort(busses.begin(), busses.end());
    int adjacency_count = 0, curr2 = 0;
    int i = 0, j = 1;
    std::string str = "";
    while (j < busses.size()) {
        while (j < busses.size() && busses[j] == busses[i] + j - i) {
            //std::cout << "\t" << busses[i] << " " << busses[j] << " " << j - i << std::endl;
            ++j;
        }
        curr = busses[i];
        curr2 = busses[j - 1];
        if (j - i > 2) {
            std::cout << curr << "-" << curr2 << " ";
            i = j;
            ++j;
        }
        else  if (j - i == 1) {
            std::cout << curr << " ";
            ++i;
            ++j;
        }
        else {
            std::cout << curr << " " << curr2 << " ";
            i = j;
            ++j;
        }
    }
    if (j == busses.size()) {
        std::cout << busses[j - 1] << " ";
    }
    std::cout << "\n";
    return 0;
}