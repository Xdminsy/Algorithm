#include <vector>
#include "SinglyLinkedList.hpp"

using namespace std;

int main(){
    auto head = LinkedListNew({1, 2, 3});
    LinkedListAppendToEnd(head, 10);
    LinkedListPrint(head);
    LinkedListInsertAfter(head->next, 9);
    LinkedListRemoveAfter(head);
    LinkedListPrint(head);
    cout << LinkedListLength(head) << endl;
    LinkedListDelete(head);

    head = LinkedListNew({});
    LinkedListPrint(head);
    cout << LinkedListLength(head) << endl;
    LinkedListDelete(head);
}