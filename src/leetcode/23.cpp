/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy, *cur = &dummy;
        auto cmp = [&](int a, int b){
            return lists[a]->val > lists[b]->val;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int len = lists.size();
        for(int i = 0; i < len; ++i)
            if(lists[i])
                pq.push(i);
        while(!pq.empty()){
            int i = pq.top();
            pq.pop();
            cur->next = lists[i];
            cur = cur->next;
            if((lists[i] = lists[i]->next) != nullptr){
                pq.push(i);
            }
        }
        return dummy.next;
    }
};
