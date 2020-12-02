#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode {

    BinaryTreeNode(): value(0), left(nullptr), right(nullptr){}
    BinaryTreeNode(int _value): value(_value), left(nullptr), right(nullptr){}
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

};

void PreOrderTraval( BinaryTreeNode *node) {

    if( node == nullptr) return;

    cout << " " << node->value << " ";

    PreOrderTraval(node->left);
    PreOrderTraval(node->right);
    return;
}

bool findPath( BinaryTreeNode *node, vector<int> &path, const int &val, int curr) {
    if( node == nullptr) return false;
    if( node->value + curr > val) return false;

    path.push_back( node->value);
    if( node->value + curr == val) {
	return true;
    }

    if( node->left) {
	bool ret = findPath( node->left, path, val, curr+node->value);
	if( ret) return true;
    }

    if( node->right) {
	bool ret = findPath( node->right, path, val, curr+node->value);
	if( ret) return true;
    }

    path.pop_back();
    return false;
}

int main(void) {

    BinaryTreeNode node1(1);
    BinaryTreeNode node2(2);
    BinaryTreeNode node3(3);
    BinaryTreeNode node4(4);
    BinaryTreeNode node5(5);
    BinaryTreeNode node6(6);
    BinaryTreeNode node7(7);
    
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node5.right = &node6;
    node3.left = &node7;


    PreOrderTraval(&node1);
    cout << endl;

    vector<int> path;
    int val = 14;
    findPath(&node1, path, val, 0);
    
    for( auto n: path) {
	cout << " " << n << " ";
    }
    cout << endl;

    return 0;
}
