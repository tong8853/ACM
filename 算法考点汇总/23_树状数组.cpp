/*
 * 考点：树状数组 (Fenwick Tree / Binary Indexed Tree)
 * 适用：单点更新 + 区间查询
 * 特点：比线段树更简单，O(log n)
 */

#include <bits/stdc++.h>
using namespace std;

class Fenwick {
public:
    int n;
    vector<int> bit;
    
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    
    // 单点更新：idx 增加 val
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    
    // 前缀和查询：[1, idx]
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
    
    // 区间和查询：[l, r]
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
    
    // 构建（从数组）
    void build(vector<int>& nums) {
        for (int i = 1; i <= n; i++) {
            bit[i] = nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int parent = i + (i & -i);
            if (parent <= n) {
                bit[parent] += bit[i];
            }
        }
    }
};

/*
 * 树状数组 vs 线段树：
 * 
 * 对比       | 树状数组     | 线段树
 * --------- | ----------- | ----------
 * 空间      | n + 1      | 4n
 * 功能      | 单点+前缀   | 全功能
 * 实现      | 简单        | 较复杂
 * 
 * 核心原理：
 * - lowbit(x) = x & -x
 * - 更新：idx += lowbit(idx)
 * - 查询：idx -= lowbit(idx)
 */
