/*
 * Problem number: #112
 * Difficulty: Easy
 */

TreeNode a = new TreeNode(5);
TreeNode b = new TreeNode(4);
TreeNode c = new TreeNode(8);
TreeNode d = new TreeNode(11);
TreeNode e = new TreeNode(13);
TreeNode f = new TreeNode(4);
TreeNode g = new TreeNode(7);
TreeNode h = new TreeNode(2);
TreeNode i = new TreeNode(1);

a.left = b;
a.right = c;
b.left = d;
b.right = null;
c.left = e;
c.right = f;
d.left = g;
d.right = h;
f.right = i;

Console.WriteLine(hasPathSum(a, 22)); // true

a = new TreeNode(1);
b = new TreeNode(2);
c = new TreeNode(3);
a.left = b;
a.right = c;

Console.WriteLine(hasPathSum(a, 5)); // false


bool hasPathSum(TreeNode root, int targetSum)
{
    if (dfs(root, targetSum, 0) == true)
        return true;
    else
        return false;
}

/*
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

bool dfs(TreeNode root, int targetSum, int currentSum)
{
    if (root == null)
        return false;

    if (dfs(root.left, targetSum, currentSum + root.val))
        return true;
    if (dfs(root.right, targetSum, currentSum + root.val))
        return true;

    if (root.left == null && root.right == null && currentSum + root.val == targetSum)
        return true;

    return false;
}

class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}