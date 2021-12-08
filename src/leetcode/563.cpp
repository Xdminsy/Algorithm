/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int result;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int fl = dfs(root->left), fr = dfs(root->right);
        result += abs(fl - fr);
        return fl + fr + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
};