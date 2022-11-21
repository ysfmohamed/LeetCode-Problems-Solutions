/*
 * Problem number: 129
 * Difficulty: Medium
 * 
 * Time Complexity: O(# of nodes)
 * Space Complexity: O(height of the tree)
 */

Node a = new Node(4);
Node b = new Node(9);
Node c = new Node(0);
Node d = new Node(5);
Node e = new Node(1);
a.left = b;
a.right = c;
b.left = d;
b.right = e;
Console.WriteLine(sumRootToLeaf(a)); // 1026

a = new Node(6);
b = new Node(2);
c = new Node(1);
d = new Node(4);
e = new Node(5);
Node f = new Node(3);
Node g = new Node(2);
Node h = new Node(7);
Node i = new Node(1);
a.left = b;
a.right = c;
b.left = d;
b.right = e;
c.right = f;
e.left = g;
e.right = h;
g.left = i;
Console.WriteLine(sumRootToLeaf(a)); // 70015

a = new Node(1);
b = new Node(2);
c = new Node(3);
d = new Node(4);
a.right = b;
b.left = c;
c.right = d;
Console.WriteLine(sumRootToLeaf(a)); // 1234

a = new Node(6);
Console.WriteLine(sumRootToLeaf(a)); // 6

a = new Node(1);
b = new Node(2);
c = new Node(2);
a.left = b;
a.right = c;
Console.WriteLine(sumRootToLeaf(a)); // 24

a = new Node(5);
b = new Node(6);
c = new Node(1);
d = new Node(1);
e = new Node(3);
f = new Node(7);
g = new Node(6);
a.left = b;
a.right = c;
c.left = d;
c.right = null;
d.left = null;
d.right = e;
e.left = null;
e.right = f;
f.left = null;
f.right = g;
Console.WriteLine(sumRootToLeaf(a)); // 511432

int sumRootToLeaf(Node root)
{
    return (int) Math.Floor(dfs(root, -1, 0));
}

decimal dfs(Node root, int level, double pathsSum)
{
    if(root == null)
        return (decimal) (pathsSum * Math.Pow(10, Math.Abs(level) - 1));

    pathsSum += root.val * Math.Pow(10, level);
    level--;

    decimal leftPath = dfs(root.left, level, pathsSum);
    decimal rightPath = dfs(root.right, level, pathsSum);

    if (root.left == null && root.right == null)
        return leftPath;

    else if (root.left != null && root.right == null)
        return leftPath;

    else if (root.left == null && root.right != null)
        return rightPath;

    else
        return leftPath + rightPath;
}
class Node
{
    public Node left;
    public int val;
    public Node right;

    public Node(int val)
    {
        this.val = val;
    }
}