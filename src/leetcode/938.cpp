#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int io = [](){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)  return 0;
        queue<TreeNode*> q;
        int sum = 0, v;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            v = root->val;
            if(root->left && v >= L) q.push(root->left);
            if(root->right && v <= R) q.push(root->right);
            if(v >= L && v <= R) sum += root->val;
        }
        return sum;
    }
};

class SolutionRecursion {
public:
    int rangeSumBST(TreeNode* root, int L, int R, int sum = 0) {
        if(!root) return sum;
        if(root->val < L) return sum + rangeSumBST(root->right, L, R, sum);
        if(root->val > R) return sum + rangeSumBST(root->left, L, R, sum);
        return root->val + sum + rangeSumBST(root->left, L, R, sum) + rangeSumBST(root->right, L, R, sum);
    }
};