/*
 * 考点：并查集 (Union-Find / Disjoint Set)
 * 适用：集合合并、连通性检测、最小生成树
 * 特点：近乎 O(1) 的合并和查找
 */

#include <bits/stdc++.h>
using namespace std;

// 并查集模板
class UnionFind {
public:
    vector<int> parent;  // 父节点
    vector<int> size;   // 集合大小
    int count;          // 连通分量数
    
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        count = n;
    }
    
    // 路径压缩（递归）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // 路径压缩（迭代，非递归）
    int findIterative(int x) {
        int root = x;
        while (parent[root] != root) {
            root = parent[root];
        }
        // 压缩路径
        while (parent[x] != x) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }
    
    // 按大小合并
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            count--;
        }
    }
    
    // 判断连通
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// ========== 应用场景 ==========

// 1. 朋友圈问题
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j]) {
                uf.unionSets(i, j);
            }
        }
    }
    return uf.count;
}

// 2. 冗余连接（树变环）
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);
    
    for (auto& edge : edges) {
        if (!uf.connected(edge[0], edge[1])) {
            uf.unionSets(edge[0], edge[1]);
        } else {
            return edge;
        }
    }
    return {};
}

// 3. 省份数量
int findNumIsConnected(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j] == 1) {
                uf.unionSets(i, j);
            }
        }
    }
    return uf.count;
}

// 4. 岛屿数量（并查集解法）
int numIslandsUF(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    UnionFind uf(m * n);
    int zeros = m * n;
    
    auto getIndex = [&](int i, int j) {
        return i * n + j;
    };
    
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                int idx = getIndex(i, j);
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n 
                        && grid[ni][nj] == '1') {
                        uf.unionSets(idx, getIndex(ni, nj));
                    }
                }
            }
        }
    }
    
    // 统计连通分量
    unordered_set<int> roots;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                roots.insert(uf.find(getIndex(i, j)));
            }
        }
    }
    return roots.size();
}

/*
 * 并查集核心操作：
 * 1. find(x)：找到根节点
 * 2. union(x, y)：合并两个集合
 * 3. connected(x, y)：判断是否连通
 * 
 * 优化技巧：
 * 1. 路径压缩：find 时把路径上的节点直接指向根
 * 2. 按大小/秩合并：小树合到大树下
 * 
 * 时间复杂度：
 * - 无优化：O(n)
 * - 路径压缩 + 按大小合并：O(α(n)) ≈ O(1)
 * 
 * 应用场景：
 * - 社交网络朋友圈
 * - 最小生成树 Kruskal
 * - 冗余连接检测
 * - 网格连通性问题
 */
