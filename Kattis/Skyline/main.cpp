#include<iostream>

struct building {
    int x1, y1, x2, y2;
};

int main() {
    int N;
    building curr, prev;
    double visibility = 1;
    for (int i = 0; i < N; ++i) {
        std::cin >> curr.x1 >> curr.y1 >> curr.x2 >> curr.y2;
        if (i == 0)
        {
            std::cout << visibility << "\n";
            prev = curr;
        }
        else {
            
        }
    }
    return 0;
}