#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
* Problem number: 99
* Difficulty: Medium
* 
* Time Complexity: O(n)
* Space Complexity: O(n)
*/

struct TreeNode {
    long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recover(TreeNode* root, vector<TreeNode*>& nodes)
{
    if (root == nullptr)
        return;

    recover(root->left, nodes);
    nodes.push_back(root);
    recover(root->right, nodes);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> nodes;

    recover(root, nodes);

    int i = 0;
    for (i = 0; i < nodes.size() - 1; i++) {
        if (!(nodes[i]->val < nodes[i + 1]->val))
            break;
    }

    int j = 0;
    for (j = nodes.size() - 1; j >= 0; j--) {
        if (!(nodes[j]->val > nodes[j - 1]->val))
            break;
    }

    swap(nodes[i]->val, nodes[j]->val);
}

int main()
{
	return 0;
}