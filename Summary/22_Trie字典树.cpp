/*
 * 考点： Trie 字典树
 * 适用：字符串前缀匹配、自动补全、IP路由
 */

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    int count;  // 以该节点为前缀的单词数
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // 插入
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count++;
        }
        node->isEnd = true;
    }
    
    // 搜索
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    // 前缀搜索
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
    
    // 获取以 prefix 为前缀的所有单词
    void getWords(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char c = 'a' + i;
                getWords(node->children[i], prefix + c, result);
            }
        }
    }
    
    vector<string> autocomplete(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return {};
            node = node->children[idx];
        }
        vector<string> result;
        getWords(node, prefix, result);
        return result;
    }
};

/*
 * Trie 特点：
 * - 空间换时间
 * - 查找 O(m)，m 为字符串长度
 * - 前缀匹配高效
 * 
 * 应用：
 * - 字符串搜索
 * - 前缀匹配
 * - IP 路由
 * - 敏感词过滤
 */
