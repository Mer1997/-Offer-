#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct BinaryTreeNode {

    BinaryTreeNode(void): val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int _val): val(_val), left(nullptr), right(nullptr) {}

    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

void _serializeBinaryTree( BinaryTreeNode *root, string &ans) {

    if( root == nullptr) {
	ans += "#";
	return;
    }

    ans += (char)('0'+root->val);
    _serializeBinaryTree( root->left, ans);
    _serializeBinaryTree( root->right, ans);

    return;
}

string serializeBinaryTree( BinaryTreeNode *root) {

    string ans = "";
    _serializeBinaryTree( root, ans);
    return ans;
}

BinaryTreeNode* deserializeBinaryTree( const string &buf, int &index) {

    if( buf[index] == '#') {
	++index;
	return nullptr;
    }

    int _val = buf[index] - '0';

    BinaryTreeNode *now = new BinaryTreeNode(_val);
    ++index;

    now->left = deserializeBinaryTree(buf, index);
    now->right = deserializeBinaryTree(buf, index);

    return now;
}

int main( void) {

    BinaryTreeNode *node1 = new BinaryTreeNode(1);
    BinaryTreeNode *node2 = new BinaryTreeNode(2);
    BinaryTreeNode *node3 = new BinaryTreeNode(3);
    BinaryTreeNode *node4 = new BinaryTreeNode(4);
    BinaryTreeNode *node5 = new BinaryTreeNode(5);
    BinaryTreeNode *node6 = new BinaryTreeNode(6);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;

    string result = serializeBinaryTree( node1);

    cout << "serialize result: " << result << endl; 

    int index = 0;
    BinaryTreeNode *root = deserializeBinaryTree( result, index);

    if( root) {
	cout << "root->val: " << root->val << endl;
    }

    if( root->right ) {
	cout << "right->val: " << root->right->val << endl;
    }

    if( root->right && root->right->left) {
	cout << "right->left->val: " << root->right->left->val << endl;
    }
    
    return 0;
}
