#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

/*
* Problem number: 113
* Difficulty: Medium
* 
* Time Complexity: O(n)
* Space Complexity: O(h) + O(n)
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int targetSum, int currentSum, vector<int>& possiblePath, vector<vector<int>>& actualPaths) {
    if (root == NULL)
        return;

    possiblePath.push_back(root->val);

    dfs(root->left, targetSum, currentSum + root->val, possiblePath, actualPaths);
    dfs(root->right, targetSum, currentSum + root->val, possiblePath, actualPaths);

    if (currentSum + root->val == targetSum && root->left == NULL && root->right == NULL)
        actualPaths.push_back(possiblePath);

    possiblePath.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    vector<int> possiblePath;
    vector<vector<int>> actualPaths;

    dfs(root, targetSum, 0, possiblePath, actualPaths);

    return actualPaths;
}

int main()
{
    struct TreeNode* a = new TreeNode(5);
    struct TreeNode* b = new TreeNode(4);
    struct TreeNode* c = new TreeNode(8);
    struct TreeNode* d = new TreeNode(11);
    struct TreeNode* e = new TreeNode(13);
    struct TreeNode* f = new TreeNode(4);
    struct TreeNode* g = new TreeNode(7);
    struct TreeNode* h = new TreeNode(2);
    struct TreeNode* i = new TreeNode(5);
    struct TreeNode* j = new TreeNode(1);

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

    vector<vector<int>> vec = pathSum(a, 22);
    for (auto way : vec)
    {
        for (auto ele : way)
        {
            cout << ele << " ";
        }
        cout << endl;
    } // {{5, 4, 11, 2}, {5, 8, 4, 5}}

    a = new TreeNode(1);
    b = new TreeNode(2);
    c = new TreeNode(3);

    vec = pathSum(a, 5);
    for (auto way : vec)
    {
        for (auto ele : way)
        {
            cout << ele << " ";
        }
        cout << endl;
    } // {}

    return 0;
}

