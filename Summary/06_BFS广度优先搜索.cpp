/*
 * 考点：BFS 广度优先搜索
 * 适用：最短路径、层序遍历、最小步数问题
 * 特点：队列实现，层层扩展
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 二叉树层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

// 2. 最短路径 - 迷宫最短路径
int shortestPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1) return -1;
    
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int,int>> q;
    
    q.push({0, 0});
    dist[0][0] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n 
                && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist[m-1][n-1];
}

// 3. 岛屿数量
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto& d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n 
                            && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return count;
}

// 4. 单词接龙 - 最短转换序列
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    
    queue<string> q;
    q.push(beginWord);
    int depth = 1;
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            string word = q.front(); q.pop();
            if (word == endWord) return depth;
            
            for (int i = 0; i < word.size(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (wordSet.count(word)) {
                        q.push(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        depth++;
    }
    return 0;
}

// 5. 双向 BFS 优化
int ladderLengthBidi(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    
    unordered_set<string> beginSet{beginWord}, endSet{endWord};
    int depth = 1;
    
    while (!beginSet.empty() && !endSet.empty()) {
        if (beginSet.size() > endSet.size()) 
            swap(beginSet, endSet);
        
        unordered_set<string> nextSet;
        for (string word : beginSet) {
            for (int i = 0; i < word.size(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (endSet.count(word)) return depth + 1;
                    if (wordSet.count(word)) {
                        nextSet.insert(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        beginSet = nextSet;
        depth++;
    }
    return 0;
}

/*
 * BFS 核心：
 * 1. 队列：存储待扩展节点
 * 2. 标记：防止重复访问
 * 3. 层次：每层节点数 = 队列大小
 * 
 * 优化技巧：
 * - 双向 BFS：起点和终点同时搜索
 * - 剪枝：提前排除不可能的路径
 */
