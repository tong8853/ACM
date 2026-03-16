/*
 * 考点：回溯算法 (Backtracking)
 * 核心：遍历 + 撤销选择
 * 适用：排列、组合、子集、棋盘问题
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 模板 ==========
void backtrack(vector<int>& nums, vector<int>& path, 
               vector<vector<int>>& result, vector<bool>& used) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;  // 剪枝：已使用
        
        used[i] = true;
        path.push_back(nums[i]);
        
        backtrack(nums, path, result, used);
        
        path.pop_back();
        used[i] = false;
    }
}

// 1. 全排列
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, path, result, used);
    return result;
}

// 2. 组合总和（可重复选）
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
                           i, path, result);  // i 不变，可重复选
        path.pop_back();
    }
}

// 3. 组合总和（不可重复选）
void combinationSum2Helper(vector<int>& candidates, int target,
                          int start, vector<int>& path,
                          vector<vector<int>>& result) {
    if (target < 0) return;
    if (target == 0) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue;  // 去重
        path.push_back(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], 
                            i + 1, path, result);
        path.pop_back();
    }
}

// 4. 子集
void subsetsHelper(vector<int>& nums, int start, 
                  vector<int>& path, vector<vector<int>>& result) {
    result.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        subsetsHelper(nums, i + 1, path, result);
        path.pop_back();
    }
}

// 5. N 皇后
bool isValid(vector<string>& board, int row, int col) {
    // 列检查
    for (int i = 0; i < row; i++) 
        if (board[i][col] == 'Q') return false;
    // 左上对角线
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    // 右上对角线
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
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
            board[row][col] = '.';
        }
    }
}

/*
 * 回溯模板：
 * result.add(path)
 * for choice in choices:
 *     path.add(choice)
 *     backtrack(remaining)
 *     path.remove(choice)
 * 
 * 剪枝技巧：
 * - 排序后去重
 * - 剪枝函数
 * - 已使用标记
 */
