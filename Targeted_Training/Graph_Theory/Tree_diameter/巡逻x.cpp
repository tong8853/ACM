#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Edge {
    int to, weight;
};

vector<Edge> adj[N];
int n, k, leaf = 1, L1, L2;
int fa[N], de[N], d[N];
bool v[N]; // 用于标记直径上的点

// 使用 vector 邻接表进行 DFS
void dfs(int x, int pre, int dist, int t) {
    de[x] = dist;
    if (t == 2) fa[x] = pre; 
    
    // 更新最远点
    if (de[x] > de[leaf]) leaf = x;
    
    for (auto &e : adj[x]) {
        if (e.to == pre) continue;
        dfs(e.to, x, dist + e.weight, t);
    }
}

// 树形 DP
void dp(int x, int pre) {
    for (auto &e : adj[x]) {
        int y = e.to;
        if (y == pre) continue;
        
        // 如果两个点都在直径上，边权视作 -1
        int current_weight = (v[x] && v[y]) ? -1 : 1;
        
        dp(y, x);
        
        // 更新直径及子树最长链
        L2 = max(L2, d[x] + d[y] + current_weight);
        d[x] = max(d[x], d[y] + current_weight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, 1});
        adj[y].push_back({x, 1});
    }

    // 第一次 DFS：找一个端点
    dfs(1, 0, 0, 1);
    
    // 重置并第二次 DFS：找直径另一个端点并记录路径
    int start_node = leaf;
    leaf = 0; // 重置 leaf 用于寻找新端点
    dfs(start_node, 0, 0, 2);
    
    L1 = de[leaf]; // 直径长度
    
    if (k == 1) {
        cout << 2 * (n - 1) - L1 + 1 << endl;
        return 0;
    }

    // 标记直径上的点
    for (int i = leaf; i != 0; i = fa[i]) v[i] = true;
    
    // DP 计算第二条路径
    dp(1, 0);
    
    cout << 2 * (n - 1) - L1 - L2 << endl;
    
    return 0;
}