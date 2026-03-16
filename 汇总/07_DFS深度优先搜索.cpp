/*
 * 考点：DFS 深度优先搜索
 * 适用：遍历、搜索、路径问题
 * 特点：递归/栈实现，深入探索
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 二叉树遍历
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

void preorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

// 2. 路径总和
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) 
        return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) 
        || hasPathSum(root->right, targetSum - root->val);
}

// 3. 全排列
void permuteHelper(vector<int>& nums, int start, 
                   vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteHelper(nums, start + 1, result);
        swap(nums[start], nums[i]);  // 回溯
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

// 4. 组合总和
void combinationSumHelper(vector<int>& candidates, int target,
                          int start, vector<int>& path,
                          vector<vector<int>>& result) {
    if (target < 0) return;
    if (target == 0) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        path.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], 
                             i, path, result);
        path.pop_back();  // 回溯
    }
}

// 5. 子集
void subsetsHelper(vector<int>& nums, int start, vector<int>& path,
                   vector<vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        subsetsHelper(nums, i + 1, path, result);
        path.pop_back();  // 回溯
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    subsetsHelper(nums, 0, path, result);
    return result;
}

// 6. N 皇后
bool isValid(vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueensHelper(int n, int row, vector<string>& board,
                        vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            solveNQueensHelper(n, row + 1, board, result);
            board[row][col] = '.';  // 回溯
        }
    }
}

// 7. 岛屿最大面积
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int maxArea = 0;
    
    function<int(int,int)> dfs = [&](int i, int j) {
        if ( || i >= mi < 0 || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;  // 标记已访问
        return 1 + dfs(i+1, j) + dfs(i-1, j) 
                  + dfs(i, j+1) + dfs(i, j-1);
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfs(i, j));
            }
        }
    }
    return maxArea;
}

/*
 * DFS 核心：
 * 1. 递归/栈实现
 * 2. 回溯：恢复状态
 * 3. 剪枝：提前排除不可能的情况
 * 
 * 回溯模板：
 * - 选择
 * - 递归
 * - 撤销选择
 * 
 * 常见问题：
 * - 全排列/组合
 * - 子集
 * - 棋盘问题（N皇后、数独）
 * - 岛屿问题
 */
