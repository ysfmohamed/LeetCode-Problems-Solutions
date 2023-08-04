#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Idea:
  Tree root may be robbed or not.

  If it is robbed so we must take the grand children (root->left->left, root->left->right, root->right->left, root->right->right)

  If it is not robbed so we must visit (root->left, root->right) without taking the root in our consideration and repeat the steps
*/

// Bruteforce solution
int robHelper(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int maxMoney = 0;

	if (root->left != nullptr) {
		maxMoney = maxMoney + robHelper(root->left->left) + robHelper(root->left->right);
	}

	if (root->right != nullptr) {
		maxMoney = maxMoney + robHelper(root->right->left) + robHelper(root->right->right);
	}

	// this line is equivalent to max(consider current root and its grandchildren, just consider two child-subtrees of current root)
	return max(maxMoney + root->val, robHelper(root->left) + robHelper(root->right));
}

// Memoization problem
int robHelper(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
	if (root == nullptr) {
		return 0;
	}

	if (dp.find(root) != dp.end()) {
		return dp[root];
	}

	int current = 0;

	if (root->left != nullptr) {
		current += robHelper(root->left->left, dp) + robHelper(root->left->right, dp);
	}

	if (root->right != nullptr) {
		current += robHelper(root->right->left, dp) + robHelper(root->right->right, dp);
	}

	return dp[root] = max(current + root->val, robHelper(root->left) + robHelper(root->right));
}

int rob(TreeNode* root) {
	unordered_map<TreeNode*, int> dp;

	return robHelper(root, dp);
}

int main()
{
	TreeNode* a = new TreeNode(3);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(3);
	TreeNode* e = new TreeNode(1);

	a->left = b;
	a->right = c;
	b->right = d;
	c->right = e;

	cout << rob(a) << endl; // 7

	a = new TreeNode(3);
	b = new TreeNode(4);
	c = new TreeNode(5);
	d = new TreeNode(1);
	e = new TreeNode(3);
	TreeNode* f = new TreeNode(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->right = f;

	cout << rob(a) << endl; // 9

	a = new TreeNode(4);
	b = new TreeNode(1);
	c = new TreeNode(2);
	d = new TreeNode(3);

	a->left = b;
	b->left = c;
	c->left = d;

	cout << rob(a) << endl; // 7

}