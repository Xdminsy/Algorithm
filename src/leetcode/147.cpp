#include "headers.h"
#include "SinglyLinkedList.hpp"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0, head), *prev, *pos, *t;
        int n = 0, c;
        head = &dummy;
        prev = head;
        while(prev->next){
            c = 0;
            pos = &dummy;
            while(c++ < n && pos->next->val < prev->next->val)
                pos = pos->next;
            ++n;
            if(pos == prev) {
                prev = prev->next;
                continue;
            }
            t = pos->next;
            pos->next = prev->next;
            prev->next = pos->next->next;
            pos->next->next = t;
        }
        return dummy.next;
    }
};

int main(){
    Solution solution;
    ListNode* head = LinkedListNew({4, 2, 1, 3});
    head = solution.insertionSortList(head);
}