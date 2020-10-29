#include<iostream>

int main() {
    int n, curr, count = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> curr;
        if (curr < 0) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}