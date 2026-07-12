#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> bfsOrder(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<int> order;
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return order;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {4},
        {}
    };
    std::vector<int> order = bfsOrder(graph, 0);
    std::vector<int> expected = {0, 1, 2, 3, 4};
    assert(order == expected);
    std::cout << "BFS tests passed.\n";
    return 0;
}
