#include<iostream>
#include<cfloat>
#include<vector>
#include<map>
#include<queue>
#include<queue>


int main () {
    int N, M;
    std::string monarch;
    std::map<std::string, std::vector<std::string>> children;
    std::map<std::string, double> royal_blood;
    std::map<std::string, int> degree; // i.e. The number of parents for a node

    std::cin >> N >> M >> monarch;    

    std::string child, first_parent, second_parent;
    for (int i = 0; i < N; ++i) {
        std::cin >> child >> first_parent >> second_parent;
        
        children[first_parent].push_back(child);
        children[second_parent].push_back(child);

        degree[child] = 2;
        // += since if its the first occurance it will be assigned zero, otherwise the value will stay the same
        degree[first_parent] += 0;
        degree[second_parent] += 0;
    }

    std::queue<std::string> queue;
    for (auto d : degree) {
        if (d.second == 0) {
            queue.push(d.first);
        }
    }

    royal_blood[monarch] = 1.0;
    
    std::string current;
    while (!queue.empty()) {
        current = queue.front();
        queue.pop();
        for (auto c : children[current]) {
            royal_blood[c] += royal_blood[current] / 2.0;
            degree[c]--;
            if (degree[c] == 0) {
                queue.push(c);
            }
        }
    }
    
    std::string best = "", tmp;
    for (int i = 0; i < M; ++i) {
        std::cin >> tmp;
        if (royal_blood[tmp] > royal_blood[best]) {
            best = tmp;
        }
    }
    std::cout << best << "\n";
    return 0;
}