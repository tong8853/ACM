/*
 * 考点：图论 - 最短路径
 * 算法：Dijkstra、Bellman-Ford、Floyd-Warshall
 */

#include <bits/stdc++.h>
using namespace std;

// 1. Dijkstra 算法（单源最短路径，非负权）
// 时间复杂度：O((V+E)logV) - 优先队列实现
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // (距离, 节点)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// 2. Bellman-Ford 算法（可处理负权）
// 时间复杂度：O(VE)
vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    // 迭代 n-1 次
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // 检测负环
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            // 存在负环
        }
    }
    return dist;
}

// 3. SPFA（队列优化的 Bellman-Ford）
vector<int> spfa(int n, vector<vector<pair<int,int>>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    vector<bool> inQueue(n, false);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);
    inQueue[src] = true;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inQueue[u] = false;
        
        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    return dist;
}

// 4. Floyd-Warshall（多源最短路径）
// 时间复杂度：O(V^3)，空间复杂度：O(V^2)
void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// 5. 朴素的 Dijkstra（矩阵）
vector<int> dijkstraNaive(int n, vector<vector<int>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;
    
    for (int i = 0; i < n; i++) {
        // 找到未访问的最小距离节点
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        
        if (dist[u] == INT_MAX) break;
        visited[u] = true;
        
        // 更新邻居
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}

/*
 * 最短路径算法选择：
 * 
 * 场景                      | 算法
 * -------------------------|----------------
 * 非负权图，单源            | Dijkstra（堆）
 * 非负权图，多源            | Floyd
 * 存在负权                  | Bellman-Ford / SPFA
 * 无负环，密集图            | Dijkstra（朴素）
 * 
 * 关键点：
 * - Dijkstra 不能处理负权边
 * - Bellman-Ford 可以检测负环
 * - SPFA 是 Bellman-Ford 的队列优化
 */
