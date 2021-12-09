#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* LinkedListNew(const std::vector<int>&& v){
    if(v.empty()) return nullptr;
    ListNode *dummy = new ListNode(), *cur = dummy;
    for(int i: v){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur = dummy->next;
    delete dummy;
    return cur;
}

void LinkedListPrint(ListNode* cur){
    bool first = true;
    std::cout << '[';
    while(cur){
        if(first) {
            first = false;
        } else {
            std::cout << ", ";
        }
        std::cout << cur->val;
        cur = cur->next;
    }
    std::cout << ']';
    std::cout << std::endl;
}

void LinkedListDelete(ListNode* cur){
    if(cur == nullptr) return;
    ListNode* next;
    while(cur){
        next = cur->next;
        delete cur;
        cur = next;
    }
}

int LinkedListLength(ListNode* cur){
    int result = 0;
    while(cur){
        ++result;
        cur = cur->next;
    }
    return result;
}

int LinkedListAppendToEnd(ListNode* cur, int val){
    if(cur == nullptr) return -1;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = new ListNode(val);
    return 0;
}

int LinkedListInsertAfter(ListNode* cur, int val){
    if(cur == nullptr) return -1;
    ListNode* next = cur->next;
    cur->next = new ListNode(val, next);
    return 0;
}

int LinkedListRemoveAfter(ListNode* cur){
    if(cur == nullptr) return -1;
    ListNode* next = cur->next, *next_next;
    if(next == nullptr) return 0;
    next_next = next->next;
    delete next;
    cur->next = next_next;
    return 0;
}

ListNode* LinkedListFind(ListNode* cur, int val){
    while(cur){
        if(cur->val == val)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

bool LinkedListExist(ListNode* cur, int val){
    return LinkedListFind(cur, val) != nullptr;
}