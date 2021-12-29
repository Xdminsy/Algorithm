// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root;
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        } else {
            root->right->next = nullptr;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

class Solution2 {
public:
    Node* connect(Node* root) {
        Node dummy, *prev, *cur;
        queue<Node*> q;
        if(root)
            q.push(root);
        int n = 1;
        while(!q.empty()){
            prev = &dummy;
            for(int i = 0; i < n; ++i){
                cur = q.front();
                q.pop();
                prev->next = cur;
                prev = cur;
                if(cur->left){
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            n *= 2;
            prev->next = NULL;
        }
        return root;
    }
};