#include <vector>
#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;


struct ComplexListNode {

    ComplexListNode(void): val(0), next(nullptr), sibling(nullptr) {}
    ComplexListNode(int _val): val(_val), next(nullptr), sibling(nullptr) {}

    int val;
    ComplexListNode *next;
    ComplexListNode *sibling;
};

void PrintList( ComplexListNode *head);

void CloneNodes( ComplexListNode *head) {

    ComplexListNode *p = head;
    while ( p != nullptr) {
	
	ComplexListNode *tmp = new ComplexListNode(p->val);
	tmp->next = p->next;
	p->next = tmp;

	p = tmp->next;
    }

    return;
}

void ConnectSiblingNode( ComplexListNode *head) {

    ComplexListNode *p = head;
    while( p != nullptr) {

	if( p->sibling) p->next->sibling = p->sibling->next;
	p = p->next->next;
    }

    return;
}

ComplexListNode* SplitCopiedList( ComplexListNode *head) {

    ComplexListNode *copied_head = head->next;
    ComplexListNode *p = head->next;

    while( p != nullptr) {

	ComplexListNode *tmp = p->next;
	if( p->next) p->next = p->next->next;

	p = p->next;
	if( tmp) delete tmp;
    }

    if( head) delete head;
    return copied_head;
}

ComplexListNode* CloneListWithComplexNode( ComplexListNode *head) {

    CloneNodes(head);
    //PrintList(head);

    ConnectSiblingNode(head);
    //PrintList(head);
    
    return SplitCopiedList(head);
}

void PrintList( ComplexListNode *head) {
    cout << "==========begin============" << endl;
    for( auto p = head; p != nullptr; p = p->next) {
	cout << "p->val: " << p->val;
	if( p->sibling) cout << "  p->sibling->val: " << p->sibling->val << endl;
	else cout << endl;
    }
    cout << "===========end=============" << endl;
}
int main(void) {

    ComplexListNode *node1 = new ComplexListNode(1);
    ComplexListNode *node2 = new ComplexListNode(2);
    ComplexListNode *node3 = new ComplexListNode(3);
    ComplexListNode *node4 = new ComplexListNode(4);
    ComplexListNode *node5 = new ComplexListNode(5);
    ComplexListNode *node6 = new ComplexListNode(6);
    ComplexListNode *node7 = new ComplexListNode(7);
    ComplexListNode *node8 = new ComplexListNode(8);


    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;


    node3->sibling = node4;
    node5->sibling = node1;
    node1->sibling = node8;
    node8->sibling = node1;

    PrintList(node1);

    ComplexListNode *copy_root;

    copy_root = CloneListWithComplexNode(node1);

    assert(copy_root->sibling->val == 8);
    assert(copy_root->next->next->sibling->val == 4);
    assert(copy_root->next->next->next->next->sibling->val == 1);
    assert(copy_root->sibling->sibling->val == 1);

    for( auto p = copy_root; p != nullptr;) {
	ComplexListNode *tmp = p;
	p=p->next;
	delete tmp;
    }

    return 0;
}
