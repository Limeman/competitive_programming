#include<unordered_map>
#include<iostream>
#include<vector>

int balance[10000];
bool visited[10000];
std::vector<std::vector<int>> friends(10000, std::vector<int>(10000));

void dfs(int person, int* sum) {
    if (visited[person]) {
        return;
    }
    visited[person] = true;
    *sum += balance[person];
    for (auto n : friends[person]) {
        if (!visited[n]) {
            dfs(n, sum);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> balance[i];
    }
    int person, comrade;
    for (int i = 0; i < m; i++) {
        std::cin >> person >> comrade;
        friends[person].push_back(comrade);
        friends[comrade].push_back(person);
    }

    bool possible = true;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        dfs(i, &sum);
        if (sum != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        std::cout << "POSSIBLE" << std::endl;
    }
    else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}