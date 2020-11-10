#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* reverseList( ListNode *now, ListNode *last) {

    if( now == nullptr) return nullptr;
    
    ListNode *head = nullptr;

    if( now->next != nullptr)
	head = reverseList( now->next, now);
    else 
	head = now;

    now->next = last;

    return head;
}

int main(void) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode *p = reverseList(head, nullptr);
    while(p) {
	cout << p->val << " -> ";
	p = p->next;
    }
    cout << "end" << endl;

    return 0;
}
