#include<iostream>

int main() {
    int e, f, c, num_bottles, remainder, count = 0;
    std::cin >> e >> f >> c;
    num_bottles = e + f;
    while (num_bottles >= c) {
        count += num_bottles / c;
        num_bottles = num_bottles / c + num_bottles % c;
    }
    std::cout << count << std::endl;
    return 0;
}