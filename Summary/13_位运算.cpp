/*
 * 考点：位运算 (Bit Manipulation)
 * 核心：利用二进制特性进行高效计算
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 基础操作 ==========

// 常用位运算
void basicOps() {
    int a = 5, b = 3;
    // 与、或、异或、取反
    int and_ab = a & b;   // 0101 & 0011 = 0001 = 1
    int or_ab = a | b;    // 0101 | 0011 = 0111 = 7
    int xor_ab = a ^ b;   // 0101 ^ 0011 = 0110 = 6
    int not_a = ~a;       // 取反
    
    // 移位
    int left = a << 1;    // 左移：乘以 2^n
    int right = a >> 1;   // 右移：除以 2^n
}

// ========== 技巧应用 ==========

// 1. 判断奇偶
bool isOdd(int n) {
    return (n & 1) == 1;
}

// 2. 交换两个数
void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;  // b = (a^b)^b = a
    a = a ^ b;  // a = (a^b)^a = b
}

// 3. 取绝对值
int absVal(int n) {
    int sign = (n >> 31);  // 负数为 -1(全1)，正数为 0
    return (n ^ sign) - sign;
}

// 4. 获取最高位 1 的位置
int highestBit(int n) {
    int pos = 0;
    while (n > 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

// 5. 判断是否是 2 的幂
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 6. 判断是否是 4 的幂
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}

// 7. 统计 1 的个数（Brian Kernighan 算法）
int countOnes(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // 消除最低位的 1
        count++;
    }
    return count;
}

// 8. 找出数组中唯一出现一次的数
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

// 9. 找出两个唯一出现一次的数
vector<int> singleNumberTwo(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) xorAll ^= num;
    
    int diff = xorAll & (-xorAll);  // 最低位的 1
    
    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diff) a ^= num;
        else b ^= num;
    }
    return {a, b};
}

// 10. 只出现一次的三个数，其他出现三次
int singleNumberIII(vector<int>& nums) {
    int seenOnce = 0, seenTwice = 0;
    for (int num : nums) {
        seenOnce = (~seenTwice) & (seenOnce ^ num);
        seenTwice = (~seenOnce) & (seenTwice ^ num);
    }
    return seenOnce;
}

// 11. 乘以 2 的幂
int multiplyPowerOfTwo(int n, int k) {
    return n << k;
}

// 12. 除以 2 的幂（向下取整）
int dividePowerOfTwo(int n, int k) {
    return n >> k;
}

// 13. 区间位运算
int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        shift++;
    }
    return m << shift;
}

// 14. 2 的幂之和
bool isSumOfPowersOfTwo(int n) {
    return (n & (n - 1)) == 0 || (n & (n + 1)) == n + 1;
}

// 15. 格雷码
vector<int> grayCode(int n) {
    vector<int> result;
    for (int i = 0; i < (1 << n); i++) {
        result.push_back(i ^ (i >> 1));
    }
    return result;
}

/*
 * 位运算技巧：
 * 1. n & (n-1)：消除最低位的 1
 * 2. n & (-n)：获取最低位的 1
 * 3. n ^ (n >> 1)：生成格雷码
 * 
 * 常见题型：
 * - 找出单独出现的数
 * - 位运算优化 DP
 * - 掩码操作
 */
