/*
 * 考点：字符串匹配
 * 算法：KMP、BM、Sunday
 */

#include <bits/stdc++.h>
using namespace std;

// ========== KMP 算法 ==========
// 核心：构建部分匹配表（最长公共前后缀）

// 构建 LPS 数组（Longest Proper Prefix which is also Suffix）
vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    
    int len = 0;  // 前一个最长公共前后缀长度
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP 搜索
vector<int> kmpSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    vector<int> result;
    
    int i = 0, j = 0;  // i: text, j: pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

// ========== Sunday 算法 ==========

vector<int> sundaySearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> shift(256, m + 1);
    
    for (int i = 0; i < m; i++) {
        shift[pattern[i]] = m - i;
    }
    
    vector<int> result;
    int i = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            result.push_back(i);
        }
        if (i + m < n) {
            i += shift[text[i + m]];
        } else {
            break;
        }
    }
    return result;
}

// ========== Rabin-Karp（哈希） ==========

int rabinKarpSearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    const int d = 256;  // 字符集大小
    const int q = 101;  // 素数
    
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    
    int p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        if (i < n - m) {
            t = ((t - text[i] * h) * d + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return -1;
}

/*
 * 字符串匹配算法对比：
 * 
 * 算法      | 预处理时间 | 匹配时间   | 空间
 * --------- | ---------- | ---------- | -----
 * 暴力      | O(1)      | O(nm)     | O(1)
 * KMP       | O(m)      | O(n)      | O(m)
 * Sunday    | O(m+σ)   | O(n)      | O(m+σ)
 * Rabin-Karp| O(m)      | O(nm)/O(n)| O(1)
 * 
 * KMP 核心：利用已匹配信息，避免回溯
 * Sunday：关注 text 中匹配段后的字符
 */
