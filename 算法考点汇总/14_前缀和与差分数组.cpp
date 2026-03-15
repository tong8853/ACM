/*
 * 考点：前缀和与差分数组
 * 适用：区间求和、区间更新问题
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 前缀和 ==========

// 1. 一维前缀和
class PrefixSum {
public:
    vector<long long> prefix;
    PrefixSum(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    // 查询 [left, right] 的和
    long long query(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

// 2. 二维前缀和
class PrefixSum2D {
public:
    vector<vector<int>> prefix;
    PrefixSum2D(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                              - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    // 查询子矩阵 (x1,y1) 到 (x2,y2) 的和
    int query(int x1, int y1, int x2, int y2) {
        return prefix[x2+1][y2+1] - prefix[x1][y2+1] 
             - prefix[x2+1][y1] + prefix[x1][y1];
    }
};

// 3. 和为 K 的子数组
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    count[0] = 1;
    int sum = 0, result = 0;
    for (int num : nums) {
        sum += num;
        result += count[sum - k];
        count[sum]++;
    }
    return result;
}

// 4. 连续子数组最大和（ Kadane 算法）
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int current = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        current = max(nums[i], current + nums[i]);
        maxSum = max(maxSum, current);
    }
    return maxSum;
}

// ========== 差分数组 ==========

// 5. 差分数组（区间增减）
class Difference {
public:
    vector<int> diff;
    Difference(vector<int>& nums) {
        diff.resize(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i-1];
        }
    }
    // 对 [left, right] 区间加 val
    void increment(int left, int right, int val) {
        diff[left] += val;
        if (right + 1 < diff.size()) {
            diff[right + 1] -= val;
        }
    }
    // 恢复原数组
    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};

// 6. 航班预订统计
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n, 0);
    for (auto& booking : bookings) {
        diff[booking[0] - 1] += booking[2];
        if (booking[1] < n) diff[booking[1]] -= booking[2];
    }
    vector<int> result(n);
    result[0] = diff[0];
    for (int i = 1; i < n; i++) {
        result[i] = result[i-1] + diff[i];
    }
    return result;
}

/*
 * 前缀和适用场景：
 * 1. 静态数组区间求和
 * 2. 子数组和为 K 的问题
 * 3. 二维矩阵子区域和
 * 
 * 差分数组适用场景：
 * 1. 区间频繁增减操作
 * 2. 最终状态查询
 * 
 * 核心思想：
 * - 前缀和：O(1) 查询区间和
 * - 差分：O(1) 区间更新
 */
