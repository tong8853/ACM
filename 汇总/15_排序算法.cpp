/*
 * 考点：排序算法
 * 分类：比较排序、非比较排序
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 比较排序 O(nlogn) ==========

// 1. 快速排序
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

// 2. 归并排序
void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];
    for (int p = 0; p < k; p++) {
        nums[left + p] = temp[p];
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

// 3. 堆排序
void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && nums[left] > nums[largest]) largest = left;
    if (right < n && nums[right] > nums[largest]) largest = right;
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
    // 排序
    for (int i = n - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

// ========== 非比较排序 O(n) ==========

// 4. 计数排序
void countingSort(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    int range = maxVal - minVal + 1;
    
    vector<int> count(range, 0);
    for (int num : nums) count[num - minVal]++;
    
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i]-- > 0) {
            nums[index++] = i + minVal;
        }
    }
}

// 5. 桶排序
void bucketSort(vector<float>& nums) {
    int n = nums.size();
    vector<vector<float>> buckets(n);
    
    // 分配到桶
    for (float num : nums) {
        int index = num * n;
        buckets[index].push_back(sort(buckets[index].begin(), 
                                      buckets[buckets[index].size()-1].end()));
    }
    
    // 合并
    int index = 0;
    for (auto& bucket : buckets) {
        for (float num : bucket) {
            nums[index++] = num;
        }
    }
}

// 6. 基数排序
void radixSort(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<vector<int>> buckets(10);
        for (int num : nums) {
            buckets[(num / exp) % 10].push_back(num);
        }
        int index = 0;
        for (auto& bucket : buckets) {
            for (int num : bucket) {
                nums[index++] = num;
            }
        }
    }
}

/*
 * 排序算法对比：
 * 
 * 算法          | 最好    | 平均    | 最坏    | 空间  | 稳定
 * -------------|---------|---------|---------|-------|----
 * 快速排序      | nlogn  | nlogn  | n^2    | logn  | 否
 * 归并排序      | nlogn  | nlogn  | nlogn  | n     | 是
 * 堆排序        | nlogn  | nlogn  | nlogn  | 1     | 否
 * 计数排序      | n+k    | n+k    | n+k    | n+k   | 是
 * 桶排序        | n      | n+k    | n^2    | n+k   | 是
 * 基数排序      | nk     | nk     | nk     | n+k   | 是
 * 
 * 稳定排序：相等元素相对位置不变
 */
