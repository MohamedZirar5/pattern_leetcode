#include <cassert>
#include <iostream>
#include <vector>

void dfsVisit(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<int>& order) {
    visited[node] = true;
    order.push_back(node);
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfsVisit(next, graph, visited, order);
        }
    }
}

std::vector<int> dfsOrder(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<int> order;
    std::vector<bool> visited(graph.size(), false);
    dfsVisit(start, graph, visited, order);
    return order;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {3},
        {4},
        {},
        {}
    };
    std::vector<int> order = dfsOrder(graph, 0);
    std::vector<int> expected = {0, 1, 3, 2, 4};
    assert(order == expected);
    std::cout << "DFS tests passed.\n";
    return 0;
}
