/*
 * 考点：线段树 (Segment Tree)
 * 适用：区间查询、区间修改
 * 特点：O(log n) 复杂度
 */

#include <bits/stdc++.h>
using namespace std;

// 线段树模板
class SegTree {
public:
    int n;
    vector<int> tree;
    
    SegTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }
    
    void build(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, nums);
            build(2 * node + 1, mid + 1, end, nums);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    // 区间查询
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) 
             + query(2 * node + 1, mid + 1, end, l, r);
    }
    
    // 点更新
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    // 区间更新（懒标记版本）
    void updateRange(int l, int val) {
        updateRange(1, 0, n - 1, l, l, val);
    }
    
    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

/*
 * 线段树 vs 树状数组：
 * 
 * 对比       | 线段树       | 树状数组
 * --------- | ----------- | ----------
 * 功能      | 更全面       | 较单一
 * 空间      | 4n          | n
 * 实现      | 较复杂       | 简单
 * 
 * 适用场景：
 * - 区间求和、最大/最小值
 * - 区间更新 + 区间查询
 */
