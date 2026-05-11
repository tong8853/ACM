/*
 * 考点：哈希表 (Hash Table)
 * 适用：快速查找、去重、计数
 * 特点：O(1) 平均查找复杂度
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 基础操作 ==========

// 1. 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// 2. 快乐数
int getSum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = getSum(n);
    }
    return n == 1;
}

// 3. 字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& p : map) {
        result.push_back(p.second);
    }
    return result;
}

// 4. 最长连续序列
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    
    for (int num : set) {
        if (!set.count(num - 1)) {
            int current = 1;
            while (set.count(num + current)) {
                current++;
            }
            longest = max(longest, current);
        }
    }
    return longest;
}

// 5. LRU 缓存
class LRUCache {
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
        } else {
            if (cache.size() == capacity) {
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};

// 6. 计数问题 - 水果成篮
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < fruits.size(); right++) {
        count[fruits[right]]++;
        
        while (count.size() > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) {
                count.erase(fruits[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

/*
 * 哈希表技巧：
 * 1. 字符计数：vector<int> count(26)
 * 2. 前缀和 + 哈希：找子数组和为 k
 * 3. 哈希 + 双指针：去重
 * 
 * unordered_map vs map：
 * - unordered_map：O(1) 平均，顺序不确定
 * - map：O(log n)，有序
 * 
 * 注意事项：
 * - 哈希冲突
 * - 负载因子
 * - 初始化容量
 */
