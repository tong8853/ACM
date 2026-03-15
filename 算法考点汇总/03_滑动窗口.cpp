/*
 * 考点：滑动窗口 (Sliding Window)
 * 适用：子串、子数组问题，要求 O(n) 时间
 * 
 * 模板：
 * 1. 固定窗口大小
 * 2. 动态窗口（双指针）
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 固定窗口大小 - 最大平均子数组
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    long long maxSum = sum;
    
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k];
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum / k;
}

// 2. 动态窗口 - 最小覆盖子串
string minWindow(string s, string t) {
    vector<int> need(128, 0), window(128, 0);
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0, start = 0, minLen = INT_MAX;
    
    while (right < s.size()) {
        char c = s[right];
        right++;
        
        if (need[c] > 0) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }
        
        // 收缩窗口
        while (valid == need.size()) {
            if (right - left < minLen) {
                start = left;
                minLen = right - left;
            }
            
            char d = s[left];
            if (need[d] > 0) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

// 3. 字符计数 + 窗口 - 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0, maxLen = 0;
    
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;
        
        // 收缩窗口直到没有重复
        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        
        maxLen = max(maxLen, right - left);
    }
    return maxLen;
}

// 4. 窗口内最大值 - 单调队列模板
class MonotonicQueue {
public:
    deque<int> q;  // 存储下标
    void push(int x) {
        while (!q.empty() && q.back() < x) q.pop_back();
        q.push_back(x);
    }
    void pop(int x) {  // x 是即将移出窗口的元素
        if (!q.empty() && q.front() == x) q.pop_front();
    }
    int max() { return q.empty() ? 0 : q.front(); }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    MonotonicQueue mq;
    
    for (int i = 0; i < nums.size(); i++) {
        mq.push(nums[i]);
        if (i >= k) mq.pop(nums[i - k]);  // 移除窗口外的元素
        if (i >= k - 1) ans.push_back(mq.max());
    }
    return ans;
}

/*
 * 核心思想：
 * 1. 维护一个滑动区间
 * 2. 右指针扩展，左指针收缩
 * 3. 单调队列：O(n) 求滑动窗口最大值
 * 
 * 关键点：
 * - 何时收缩窗口
 * - 如何判断条件满足
 * - 边界条件处理
 */
