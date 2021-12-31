#include "headers.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* root, int maxAncestor, int minAncestor){
        if(root == nullptr) return 0;
        maxAncestor = max(maxAncestor, root->val);
        minAncestor = min(minAncestor, root->val);
        int maxLeft = dfs(root->left, maxAncestor, minAncestor);
        int maxRight = dfs(root->right, maxAncestor, minAncestor);
        return max(
                max(abs(root->val - minAncestor), abs(root->val - maxAncestor)),
                max(maxLeft, maxRight));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return root ? dfs(root, root->val, root->val) : 0;
    }
};
