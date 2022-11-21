#include <iostream>
#include <vector>
using namespace std;

/*
* Problem number: 437
* Difficulty: Medium
* 
* Time Comlexity: O(n^2)
* Space Complexity: O(n)
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void dfs(TreeNode* root, int targetSum, vector<int>& paths, int& count)
{
	if (root == nullptr)
		return;

	paths.push_back(root->val);
	dfs(root->left, targetSum, paths, count);
	dfs(root->right, targetSum, paths, count);

	long long int sum = 0;
	for (int i = paths.size() - 1; i >= 0; i--)
	{
		sum += paths[i];
		if (sum == targetSum)
			count++;
	}

	paths.pop_back();
}

int pathSum(TreeNode* root, int targetSum)
{
	vector<int> paths;
	int count = 0;

	dfs(root, targetSum, paths, count);

	return count;
}

int main()
{
	TreeNode* a = new TreeNode(10);
	TreeNode* b = new TreeNode(5);
	TreeNode* c = new TreeNode(-3);
	TreeNode* d = new TreeNode(3);
	TreeNode* e = new TreeNode(2);
	TreeNode* f = new TreeNode(11);
	TreeNode* g = new TreeNode(3);
	TreeNode* h = new TreeNode(-2);
	TreeNode* i = new TreeNode(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->right = f;
	d->left = g;
	d->right = h;
	e->right = i;

	cout << pathSum(a, 8) << endl;

	a = new TreeNode(5);
	b = new TreeNode(4);
	c = new TreeNode(8);
	d = new TreeNode(11);
	e = new TreeNode(13);
	f = new TreeNode(4);
	g = new TreeNode(7);
	h = new TreeNode(2);
	i = new TreeNode(5);
	TreeNode* j = new TreeNode(1);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = NULL;
	c->left = e;
	c->right = f;
	d->left = g;
	d->right = h;
	e->left = NULL;
	e->right = NULL;
	f->left = i;
	f->right = j;

	cout << pathSum(a, 22) << endl;
}