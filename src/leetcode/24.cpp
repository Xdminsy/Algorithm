#include "headers.h"
#include "SinglyLinkedList.hpp"

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
    ListNode* swapPairs(ListNode *head) {
        if(head && head->next){
            ListNode *next = head->next;
            head->next = swapPairs(next->next);
            next->next = head;
            return next;
        }
        return head;
    }
};
class SolutionIterate {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy, *first = &dummy, *temp;
        dummy.next = head;
        while(first->next && first->next->next){
            temp = first->next->next;
            first->next->next = temp->next;
            temp->next = first->next;
            first->next = temp;
            first = first->next->next;
        }
        return dummy.next;
    }
};