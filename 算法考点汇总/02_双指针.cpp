/*
 * 考点：双指针 (Two Pointers)
 * 适用：有序数组、链表、字符串等需要 O(n) 复杂度的问题
 * 
 * 分类：
 * 1. 对撞指针：左右向中间移动
 * 2. 滑动窗口：维护一个窗口
 * 3. 快慢指针：同向移动，一快一慢
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 对撞指针 - 两数之和（有序数组）
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

// 2. 滑动窗口 - 最大子数组和
int maxSubArraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (i >= k) sum -= nums[i - k];  // 窗口大小为 k
        if (i >= k - 1) maxSum = max(maxSum, sum);
    }
    return maxSum;
}

// 滑动窗口模板（通用）
int slidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int windowSum = 0, ans = 0;
    
    while (right < n) {
        windowSum += nums[right];  // 加入元素
        
        // 收缩窗口条件
        while (right - left + 1 > k) {
            windowSum -= nums[left];
            left++;
        }
        
        // 更新答案
        ans = max(ans, windowSum);
        right++;
    }
    return ans;
}

// 3. 快慢指针 - 环形链表检测
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;        // 慢指针走一步
        fast = fast->next->next;  // 快指针走两步
        
        if (slow == fast) return true;  // 相遇则有环
    }
    return false;
}

// 4. 去除有序数组中的重复元素
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

/*
 * 核心思想：
 * 1. 对撞指针：利用有序性，两端逼近
 * 2. 滑动窗口：维护一个区间，常用于子串问题
 * 3. 快慢指针：检测环、找到中点
 * 
 * 时间复杂度：通常 O(n)
 * 空间复杂度：O(1)
 */
