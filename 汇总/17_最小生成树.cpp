/*
 * 考点：图论 - 最小生成树
 * 算法：Kruskal、Prim
 */

#include <bits/stdc++.h>
using namespace std;

// ========== Kruskal 算法 ==========
// 思想：贪心 + 并查集
// 时间复杂度：O(ElogE)

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int mstWeight = 0;
    int edgeCount = 0;
    
    for (auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mstWeight += edge.w;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }
    return mstWeight;
}

// ========== Prim 算法 ==========
// 思想：贪心 + 优先队列
// 时间复杂度：O(ElogV)

int prim(int n, vector<vector<pair<int,int>>>& graph) {
    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    minDist[0] = 0;
    pq.push({0, 0});
    int mstWeight = 0;
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        mstWeight += dist;
        
        for (auto& [v, w] : graph[u]) {
            if (!visited[v] && w < minDist[v]) {
                minDist[v] = w;
                pq.push({w, v});
            }
        }
    }
    return mstWeight;
}

/*
 * Kruskal vs Prim：
 * 
 * 对比           | Kruskal         | Prim
 * ------------- | --------------- | ---------------
 * 思想          | 边贪心          | 点贪心
 * 适用          | 稀疏图          | 稠密图
 * 实现          | 并查集 + 排序   | 优先队列
 * 时间复杂度    | O(ElogE)       | O(ElogV)
 * 
 * 共同点：
 * - 都是贪心算法
 * - 都能得到最小生成树
 * - 都要求图是无向连通的
 */
