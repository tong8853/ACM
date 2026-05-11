#include <vector>
#include <stack>

using namespace std;

//https://ac.nowcoder.com/acm/problem/234813

class Solution {
public:
    /**
     * @param nums int整型vector 
     * @return int整型vector
     */
    vector<int> nextBigger(vector<int>& nums) {
        int n = nums.size();
        // 1. 初始化结果数组为 -1，处理不存在更大元素的情况
        vector<int> ans(n, -1);
        
        // 2. 栈中只存放元素的索引（Index），方便直接操作 ans 数组
        // 栈内索引对应的元素值保持单调递减
        stack<int> st;

        // 3. 模拟遍历两遍数组 (i 从 0 到 2n-1)
        for (int i = 0; i < 2 * n; ++i) {
            // 通过取模运算获取当前循环下的实际数值
            int x = nums[i % n];

            // 4. 当栈不为空，且当前元素大于栈顶索引对应的元素时
            // 说明找到了栈顶元素的“第一个比它大的元素”
            while (!st.empty() && x > nums[st.top()]) {
                ans[st.top()] = x;
                st.pop();
            }

            // 5. 只有在第一轮遍历时才将索引入栈
            // 第二轮遍历的目的是为了消耗掉第一轮遍历后栈内剩余的索引
            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};