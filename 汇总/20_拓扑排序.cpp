/*
 * 考点：拓扑排序
 * 适用：依赖排序、任务调度、课程先修
 * 前提：图是有向无环图 (DAG)
 */

#include <bits/stdc++.h>
using namespace std;

// 1. Kahn 算法（BFS + 入度）
vector<int> topologicalSortKahn(int n, vector<vector<int>>& graph) {
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    
    if (result.size() != n) {
        // 存在环，拓扑排序不存在
    }
    return result;
}

// 2. DFS 方法（后序遍历 + 逆序）
void dfs(int u, vector<vector<int>>& graph, 
         vector<int>& visited, vector<int>& result) {
    visited[u] = 1;  // 正在访问
    for (int v : graph[u]) {
        if (visited[v] == 0) {
            dfs(v, graph, visited, result);
        } else if (visited[v] == 1) {
            // 发现回边，存在环
        }
    }
    visited[u] = 2;  // 访问完成
    result.push_back(u);  // 后序加入
}

vector<int> topologicalSortDFS(int n, vector<vector<int>>& graph) {
    vector<int> visited(n, 0);
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, graph, visited, result);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

// 3. 课程表（检测环 + 返回顺序）
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        count++;
        for (int next : graph[course]) {
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    return count == numCourses;
}

/*
 * 拓扑排序核心：
 * 1. 找入度为 0 的节点
 * 2. 删除该节点及其出边
 * 3. 重复直到为空
 * 
 * 适用场景：
 * - 任务调度
 * - 课程先修
 * - 依赖安装
 * - 编译顺序
 */
