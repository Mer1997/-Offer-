#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) :val(x), next(next) {} 
};

void printListReversingly(ListNode* node) {

    if( node == nullptr ) {
	return;
    }

    printListReversingly(node->next);
    cout << " " << node->val << " ";

    return;
}

int main(void) {
    vector<ListNode> vec = {0,1,2,3,4,5};

    ListNode *head = &vec[0];
    ListNode *p = head;
    for(auto &v: vec) {
	if( head == &v ) continue;
	p->next = &v;
	p = p->next;
    }
    p = nullptr;

    printListReversingly(head);
    cout << endl;
    return 0;
}
