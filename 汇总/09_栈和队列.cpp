/*
 * 考点：栈和队列
 * 适用：匹配问题、单调栈、层序遍历、滑动窗口最大值
 */

#include <bits/stdc++.h>
using namespace std;

// 1. 有效括号
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

// 2. 每日温度 - 单调栈
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;  // 存下标
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top(); st.pop();
            ans[prev] = i - prev;
        }
        st.push(i);
    }
    return ans;
}

// 3. 下一个更大元素
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return ans;
}

// 4. 柱状图中最大的矩形
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i <= heights.size(); i++) {
        int h = (i == heights.size() ? 0 : heights[i]);
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

// 5. 接雨水
int trap(vector<int>& height) {
    stack<int> st;
    int water = 0;
    
    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top(); st.pop();
            if (st.empty()) break;
            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }
        st.push(i);
    }
    return water;
}

// 6. 用队列实现栈
class MyStack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        swap(q1, q2);
        return val;
    }
    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        q2.push(val);
        swap(q1, q2);
        return val;
    }
    bool empty() {
        return q1.empty();
    }
};

// 7. 用栈实现队列
class MyQueue {
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/*
 * 栈的应用：
 * 1. 括号匹配
 * 2. 单调栈：找下一个更大/更小元素
 * 3. 深度优先搜索
 * 4. 表达式求值
 * 
 * 队列的应用：
 * 1. 广度优先搜索
 * 2. 滑动窗口
 * 3. 层次遍历
 * 
 * 单调栈模板：
 * for (从后往前遍历) {
 *     while (!st.empty() && 当前元素 <= st.top()) st.pop();
 *     ans[i] = st.empty() ? -1 : st.top();
 *     st.push(当前元素);
 * }
 */
