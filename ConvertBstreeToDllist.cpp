#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode {

    BinaryTreeNode(void): val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}

    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

struct DoubleLinkedListNode {
    
    DoubleLinkedListNode(void): val(0), prev(nullptr), next(nullptr) {}
    DoubleLinkedListNode(int _val): val(_val), prev(nullptr), next(nullptr) {}

    int val;
    DoubleLinkedListNode *prev;
    DoubleLinkedListNode *next;
};

/*********************TODO*****************************/
DoubleLinkedListNode* ConvertBstreeToDllist( BinaryTreeNode *root) {

    if( root == nullptr) return nullptr;

    DoubleLinkedListNode *prev = nullptr;
    DoubleLinkedListNode *tail = nullptr;

    if( root->left) prev = ConvertBstreeToDllist( root->left);
    
    DoubleLinkedListNode *mid = new DoubleLinkedListNode(root->val);

    if( prev) {
	prev->next = mid;
	mid->prev = prev;
    }

    if( root->right) tail = ConvertBstreeToDllist( root->right);

    if( tail) {
	DoubleLinkedListNode *p = tail;
	while(p->prev != nullptr) p = p->prev;
	mid->next = p;
	p->prev = mid;
	return tail;
    }

    return mid;

}
/********************TODO END*****************************/

int main( void) {

    BinaryTreeNode node1(10);
    BinaryTreeNode node2(6);
    BinaryTreeNode node3(14);
    BinaryTreeNode node4(4);
    BinaryTreeNode node5(8);
    BinaryTreeNode node6(12);
    BinaryTreeNode node7(16);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;

    auto head = ConvertBstreeToDllist( &node1);

    for( auto p = head; p != nullptr; p=p->prev) {
	cout << "p->val: " << p->val << endl;
    }

    for( auto p = head; p != nullptr; ) {
	auto tmp = p;
	p = p->prev;
	delete tmp;
    }

    return 0;
}
