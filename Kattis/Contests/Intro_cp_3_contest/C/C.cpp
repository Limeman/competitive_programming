#include<iostream>
#include<map>

int main() {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);

    int curr, n;
    std::map<int, int> heights;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> curr;
        heights[i] = curr;
    }
    int i = 0, j = 1, shotcount = n;
    while (j < n) {
        //std::cout << heights[i] - (j - i) << " " << heights[j]<< std::endl;
        if (heights[i] != -1) {
            for (;j < n; ++j) {
                if (heights[j] != -1 && heights[i] - (j - i) == heights[j]) {
                    heights[j] = -1;
                    --shotcount;
                }
            }
        }
        ++i;
        j = i + 1;
    }
    std::cout << shotcount << std::endl;
    return 0;
}