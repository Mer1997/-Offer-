#include <iostream>

using namespace std;

struct ListNode {

    ListNode (void): val(0), _prev(nullptr), _next(nullptr) {}
    ListNode (int _val): val(_val), _prev(nullptr), _next(nullptr) {}

    int val;
    ListNode *_prev;
    ListNode *_next;

};

ListNode* getEntryNodeOfLoop( ListNode *head) {

    ListNode *fast = head;
    ListNode *slow = head;

    do {

	slow = slow->_next;

	fast = fast->_next->_next;

    }while( fast != slow);

    slow = head;

    while( slow != fast) {

	slow = slow->_next;

	fast = fast->_next;
    }


    return slow;
}

int main(void) {

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(7);
    ListNode node8(8);

    node1._next = &node2;
    node2._next = &node3;
    node3._next = &node4;
    node4._next = &node5;
    node5._next = &node6;
    node6._next = &node7;
    node7._next = &node3;

    ListNode *entry = getEntryNodeOfLoop( &node1 );

    cout << "the entry node of loop is " << entry->val << endl;

    return 0;
}
