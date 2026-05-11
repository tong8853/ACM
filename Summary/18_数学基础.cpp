/*
 * 考点：数学基础
 * 内容：质数、GCD、快速幂、取模运算
 */

#include <bits/stdc++.h>
using namespace std;

// ========== 质数相关 ==========

// 1. 质数判断
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 2. 埃拉托斯特尼筛法
vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

// 3. 线性筛
vector<int> linearSieve(int n) {
    vector<int> primes;
    vector<int> minFactor(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minFactor[i]) {
            minFactor[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > minFactor[i] || i * p > n) break;
            minFactor[i * p] = p;
        }
    }
    return primes;
}

// ========== GCD 与 LCM ==========

// 4. 欧几里得算法（辗转相除）
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 5. 扩展欧几里得（求 ax + by = gcd(a,b) 的解）
long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// 6. LCM
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// ========== 快速幂 ==========

// 7. 快速幂（递归）
long long fastPow(long long a, long long n) {
    if (n == 0) return 1;
    long long res = fastPow(a, n / 2);
    if (n % 2 == 0) return res * res;
    else return res * res * a;
}

// 8. 快速幂（迭代）
long long fastPowIter(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

// 9. 快速幂取模
long long modPow(long long a, long long n, long long mod) {
    long long res = 1;
    a %= mod;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

// ========== 取模运算 ==========

// 10. 组合数取模（Lucas 定理）
long long combMod(long long n, long long m, long long p) {
    if (m == 0) return 1;
    return combMod(n / p, m / p, p) 
         * combMod(n % p, m % p, p) % p;
}

// 11. 卡特兰数
long long catalan(int n) {
    long long C = 1;
    for (int i = 0; i < n; i++) {
        C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return C;
}

// ========== 位运算数学 ==========

// 12. 判断是否是 2 的幂
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 13. 统计二进制中 1 的个数
int countOnes(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

/*
 * 数论要点：
 * 1. 质数筛法：普通 O(nlogn)，线性 O(n)
 * 2. gcd：欧几里得算法
 * 3. 快速幂：O(logn)
 * 4. 取模：注意 (a*b)%mod = ((a%mod)*(b%mod))%mod
 */
