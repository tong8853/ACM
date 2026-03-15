/*
 * 考点：分治算法 (Divide and Conquer)
 * 核心：将大问题分解为小问题，解决后合并
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 归并排序（分治）
void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];
    for (int p = 0; p < k; p++) nums[left + p] = temp[p];
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);       // 分解左半
    mergeSort(nums, mid + 1, right);  // 分解右半
    merge(nums, left, mid, right);    // 合并结果
}

// 2. 快速排序（分治）
void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= pivot) j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= pivot) i++;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

// 3. 最大子数组和（分治）
int maxSubArray(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];
    int mid = left + (right - left) / 2;
    
    int leftMax = maxSubArray(nums, left, mid);
    int rightMax = maxSubArray(nums, mid + 1, right);
    
    // 跨越中点的最大和
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        rightSum = max(rightSum, sum);
    }
    int crossMax = leftSum + rightSum;
    
    return max({leftMax, rightMax, crossMax});
}

// 4. Pow(x, n)
double myPow(double x, long long n) {
    if (n == 0) return 1;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double half = myPow(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return half * half * x;
}

/*
 * 分治步骤：
 * 1. 分解：将问题分成子问题
 * 2. 解决：递归解决子问题
 * 3. 合并：合并子问题的解
 * 
 * 经典分治算法：
 * - 归并排序
 * - 快速排序
 * - 最大子数组和
 * - Pow(x, n)
 * - 二分查找
 * - 大整数乘法
 */
