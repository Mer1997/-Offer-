#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

TreeNode* rebuildTree( vector<int> preOrder, int l_left, int l_right, vector<int> inOrder, int r_left, int r_right) {
    
    assert( preOrder.size() == inOrder.size());
    if( l_left >= l_right) return nullptr;

    TreeNode *head = new TreeNode( preOrder[l_left]);
    for( int index = r_left; index != r_right; index++) {
	if( preOrder[l_left] == inOrder[index]) {
	    
	    int size = index - r_left;
	    head->left = rebuildTree( preOrder, l_left+1, l_left+size+1, inOrder, r_left, index);
	    head->right = rebuildTree( preOrder, l_left+size+1, l_right, inOrder, index+1, r_right);
	    break;
	}
    }

    return head;
}

void printTreeByTailOrder( TreeNode *head) {

    if( head == nullptr) {
	return;
    }

    printTreeByTailOrder( head->left);
    printTreeByTailOrder( head->right);

    cout << head->val << " ";

}

int main(void) {
    
    vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6 };

    TreeNode *head = rebuildTree(preOrder, 0, preOrder.size(), inOrder, 0, inOrder.size());

    printTreeByTailOrder( head);
    cout << endl;

    return 0;
}
