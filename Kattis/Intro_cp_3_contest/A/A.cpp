#include<iostream>

int main() {
    int datacap, n, data_available = 0, curr;
    std::cin >> datacap >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> curr;
        data_available += datacap - curr;
    }
    std::cout << datacap + data_available << std::endl;
    return 0;
}