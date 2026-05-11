/*
 * 考点：二分查找 (Binary Search)
 * 适用：有序数组中查找目标值，或者寻找满足条件的边界
 * 
 * 模板：
 * 1. 查找精确值：left <= right, left = mid + 1, right = mid - 1
 * 2. 查找左边界：left < right, right = mid, left = mid + 1
 * 3. 查找右边界：left < right, left = mid, right = mid - 1
 */

#include <bits/stdc++.h>
using namespace std;

// 模板1：查找精确值
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 模板2：查找左边界（第一个 >= target 的位置）
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();  // right 可以是 size
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// 模板3：查找右边界（第一个 > target 的位置）
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// 二分答案：适用于最大化最小值、最小化最大值问题
bool check(int mid, vector<int>& nums, int target) {
    // 自定义检查条件
    return true;
}
int binaryAnswer(int left, int right, vector<int>& nums, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(mid, nums, target)) right = mid;  // 答案在左半边
        else left = mid + 1;
    }
    return left;
}

/*
 * 关键点：
 * 1. mid = left + (right - left) / 2 防止溢出
 * 2. left < right vs left <= right 的选择
 * 3. left = mid + 1 vs left = mid 的选择
 * 4. right = mid - 1 vs right = mid 的选择
 * 5. 二分答案的思想：单调性
 */
