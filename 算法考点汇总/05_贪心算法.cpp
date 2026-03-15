/*
 * 考点：贪心算法 (Greedy)
 * 核心：每步选择局部最优，期望得到全局最优
 * 适用：具有贪心选择性质的问题
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 区间调度 - 最多不重叠区间数
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b){ return a[1] < b[1]; });
    
    int count = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }
    return intervals.size() - count;
}

// 2.  Huffman 编码思想 - 最小成本合并石头
int mergeStones(vector<int>& stones, int K) {
    int n = stones.size();
    if ((n - 1) % (K - 1)) return -1;
    
    // 排序 + 优先队列
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int s : stones) pq.push(s);
    
    int cost = 0;
    while (pq.size() > 1) {
        int sum = 0;
        for (int i = 0; i < K; i++) {
            sum += pq.top(); pq.pop();
        }
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

// 3. 会议安排 - 最少会议室
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    vector<int> starts, ends;
    for (auto& i : intervals) {
        starts.push_back(i[0]);
        ends.push_back(i[1]);
    }
    sort(starts.begin(), ends.end());
    sort(ends.begin(), ends.end());
    
    int rooms = 0, j = 0;
    for (int i = 0; i < starts.size(); i++) {
        if (starts[i] < ends[j]) rooms++;
        else j++;
    }
    return rooms;
}

// 4. 股票买卖最佳时机（冷冻期）
int maxProfitWithCoolDown(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int dp0 = 0, dp1 = -prices[0], dp2 = 0;
    for (int i = 1; i < n; i++) {
        int newDp0 = max(dp0, dp1 + prices[i]);
        int newDp1 = max(dp1, dp2 - prices[i]);
        int newDp2 = max(dp2, dp0);
        dp0 = newDp0; dp1 = newDp1; dp2 = newDp2;
    }
    return max(dp0, dp2);
}

// 5. 跳跃游戏
bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

// 6. 加油站 - 环形路径问题
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) {
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

// 7. 划分字母区间
vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);
    for (int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;
    }
    
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}

/*
 * 贪心适用条件：
 * 1. 最优子结构：局部最优 → 全局最优
 * 2. 无后效性：当前选择不影响未来
 * 
 * 常见贪心策略：
 * - 排序：按结束时间、价值等排序
 * - 优先队列：最大/最小值优先
 * - 区间贪心：选最早结束的
 */
