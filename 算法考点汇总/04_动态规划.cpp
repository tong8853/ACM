/*
 * 考点：动态规划 (Dynamic Programming)
 * 核心：最优子结构 + 重叠子问题
 * 
 * 解题步骤：
 * 1. 确定状态定义 dp[i]
 * 2. 确定状态转移方程
 * 3. 确定初始条件和边界
 * 4. 遍历顺序
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 1. 基础 DP ==========

// 爬楼梯（斐波那契）
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// 打家劫舍（相邻房间不能偷）
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}

// ========== 2. 背包问题 ==========

// 0/1 背包（一维优化）
int knapsack01(int W, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

// 完全背包（正序遍历）
int knapsackComplete(int W, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int j = weights[i]; j <= W; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

// ========== 3. 子序列问题 ==========

// 最长公共子序列 LCS
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// 最长递增子序列 LIS（贪心 + 二分 O(nlogn)）
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int x : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

// ========== 4. 股票问题 ==========

// 买卖股票最佳时机（一次交易）
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}

// 买卖股票最佳时机（多次交易）
int maxProfitII(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }
    return profit;
}

// ========== 5. 字符串 DP ==========

// 编辑距离
int minDistance(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
    return dp[n][m];
}

/*
 * DP 分类：
 * 1. 线性 DP：状态沿一个方向
 * 2. 区间 DP：状态是区间 [l, r]
 * 3. 树形 DP：在树上做 DP
 * 4. 状态压缩 DP：用位运算表示状态
 * 
 * 优化方向：
 * - 空间优化：一维/滚动数组
 * - 时间优化：单调队列、斜率优化
 */
