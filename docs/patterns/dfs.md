# Depth-First Search (DFS)

DFS explores as far as possible along one path before backtracking. It is the right pattern for tree recursion, connected components, and backtracking-style problems.

## When it fits

- You need recursive tree traversal.
- You need to explore all paths or components.
- You need backtracking over choices.

## Core idea

Visit a node, recurse into its neighbors or children, then return to the previous call when you hit a dead end.

## Example (C++)

```cpp
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
```

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$ in the worst case because of recursion and the visited array.

## Mistake to avoid

Do not forget the visited set on graphs with cycles; otherwise DFS can recurse forever.