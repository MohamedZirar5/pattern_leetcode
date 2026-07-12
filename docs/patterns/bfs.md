# Breadth-First Search (BFS)

BFS explores a graph or tree level by level. It is the natural pattern when you want the shortest number of edges in an unweighted graph.

## When it fits

- You need level-order traversal.
- You want shortest path in an unweighted graph.
- You need to expand from multiple starting points.

## Core idea

Use a queue. Push the starting node(s), then repeatedly pop the front node and visit its neighbors.

## Example (C++)

```cpp
#include <vector>
#include <queue>

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
```

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$

## Mistake to avoid

Mark nodes as visited when you enqueue them, not when you pop them, to avoid duplicates in the queue.