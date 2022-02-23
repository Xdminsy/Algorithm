/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *entrance = new Node(node->val);
        queue<Node*> q;
        map<Node*, Node*> m;
        q.push(node);
        m[node] = entrance;
        while(!q.empty()){
            Node *curFrom = q.front(), *curTo = m[curFrom];
            q.pop();
            for(Node *n: curFrom->neighbors){
                if(!m.count(n)){
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                curTo->neighbors.push_back(m[n]);
            }
        }
        return entrance;
    }
};
