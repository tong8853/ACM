/*
 * 考点：树（二叉树遍历与构建）
 * 核心：递归思想
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ========== 遍历 ==========

// 1. 前序遍历（根-左-右）
void preorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

// 2. 中序遍历（左-根-右）
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// 3. 后序遍历（左-右-根）
void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

// 4. 层序遍历（BFS）
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

// ========== 构建 ==========

// 5. 从前序和中序构建树
TreeNode* buildFromPreIn(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>& inorder, int inStart, int inEnd) {
    if (preStart > preEnd) return nullptr;
    
    int rootVal = preorder[preStart];
    int index = inStart;
    while (inorder[index] != rootVal) index++;
    
    int leftSize = index - inStart;
    
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildFromPreIn(preorder, preStart + 1, preStart + leftSize,
                                 inorder, inStart, index - 1);
    root->right = buildFromPreIn(preorder, preStart + leftSize + 1, preEnd,
                                 inorder, index + 1, inEnd);
    return root;
}

// 6. 从中序和后序构建树
TreeNode* buildFromPostIn(vector<int>& inorder, int inStart, int inEnd,
                          vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd) return nullptr;
    
    int rootVal = postorder[postEnd];
    int index = inStart;
    while (inorder[index] != rootVal) index++;
    
    int leftSize = index - inStart;
    
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildFromPostIn(inorder, inStart, index - 1,
                                  postorder, postStart, postStart + leftSize - 1);
    root->right = buildFromPostIn(inorder, index + 1, inEnd,
                                  postorder, postStart + leftSize, postEnd - 1);
    return root;
}

// ========== 路径问题 ==========

// 7. 二叉树最大深度
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 8. 路径总和
bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) {
        return root->val == sum;
    }
    return hasPathSum(root->left, sum - root->val) 
        || hasPathSum(root->right, sum - root->val);
}

// 9. 二叉树直径
int diameter = 0;
int depth(TreeNode* root) {
    if (!root) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    depth(root);
    return diameter;
}

// 10. 翻转二叉树
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// 11. 验证二叉搜索树
bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val)
        && isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// 12. 二叉搜索树转双向链表
TreeNode* prevNode = nullptr;
TreeNode* firstNode = nullptr;

void inorderConvert(TreeNode* node) {
    if (!node) return;
    inorderConvert(node->left);
    
    if (prevNode) {
        prevNode->right = node;
        node->left = prevNode;
    } else {
        firstNode = node;
    }
    prevNode = node;
    
    inorderConvert(node->right);
}

TreeNode* treeToDoublyList(TreeNode* root) {
    if (!root) return nullptr;
    inorderConvert(root);
    firstNode->left = prevNode;
    prevNode->right = firstNode;
    return firstNode;
}

/*
 * 二叉树要点：
 * 1. 遍历顺序决定性质
 * 2. 前+中 → 唯一树
 * 3. 中+后 → 唯一树
 * 4. 前+后 → 不唯一
 */
