#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {

    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(void): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

auto GetKthNode(const TreeNode *root, int &k)->int {

    if( root == nullptr ) return -1;

    if( k == 0 ) return root->val;

    if( !root->left && !root->right ) {
	k--;
	return -1;
    }

    if( root-> left ) {
	int ret = GetKthNode(root->left, k);
	if( ret != -1 && k == 0) {
	    return ret;
	}    
    }

    if( k == 0 ) return root->val;
    k--;

    if( root-> right) {
	int ret = GetKthNode(root->right, k);
	if( ret != -1 && k == 0) {
	    return ret;
	}
    }

    return -1;
}

int main(void) {

    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node5.left = &node3;
    node3.left = &node2;
    node3.right= &node4;
    node5.right= &node7;
    node7.left = &node6;
    node7.right= &node8;

    int k = 6-1;
    int val = GetKthNode(&node5, k);

    cout << "The kth node in BSTree is " << val << endl;
    return 0;
}
