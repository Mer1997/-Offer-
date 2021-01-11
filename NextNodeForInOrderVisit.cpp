#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {}

};

TreeNode* getNextNode( TreeNode *node) {

    if( node == nullptr) return nullptr;
    TreeNode *next;

    if( node->right != nullptr) {
	TreeNode *right = node->right;
	while( right->left != nullptr) {
	    right = right->left;
	}

	next = right;
    }else if( node->parent != nullptr) {
	TreeNode *current = node;
	TreeNode *parent = node->parent;
	while( parent != nullptr && current == parent->right) {
	    current = parent;
	    parent = parent->parent;
	}

	next = parent;
    }

    return next;
}

int main(void) {

    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(6);
    head->left->left->right = new TreeNode(7);
    head->right->right->left = new TreeNode(8);

    head->parent = nullptr;
    head->left->parent = head;
    head->right->parent = head;
    head->left->left->parent = head->left;
    head->right->left->parent = head->right;
    head->right->right->parent = head->right;
    head->left->left->right->parent = head->left->left;
    head->right->right->left->parent = head->right->right;


    TreeNode *p = head;
    while( p) {
	cout << p->val << " ";
	p = getNextNode(p);
    }
    cout << endl;

    return 0;
}
