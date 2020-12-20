#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {

    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode (void): val(0), left(nullptr), right(nullptr) {}
    TreeNode (int val): val(val), left(nullptr), right(nullptr) {}
};

auto getDeepthOfBinaryTree(const TreeNode *root, const int &cur_deep) ->int {

    if( root == nullptr ) return cur_deep-1;

    int max_deep = cur_deep;

    if( root-> left ) {
	int ret = getDeepthOfBinaryTree(root->left, cur_deep+1);
	max_deep = ret > max_deep ? ret : max_deep;
    }
    
    if( root-> right ) {
	int ret = getDeepthOfBinaryTree(root->right, cur_deep+1);
	max_deep = ret > max_deep ? ret : max_deep;
    }

    return max_deep;
}

int main(void) {

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node1.left = &node2;
    node2.left = &node4;
    node2.right= &node5;
    node5.left = &node7;
    node1.right= &node3;
    node3.right= &node6;
    node5.right= &node8;

    int ans = getDeepthOfBinaryTree(&node1, 1);

    cout << "the deepth of this binary tree is " << ans << endl;
    return 0;
}
