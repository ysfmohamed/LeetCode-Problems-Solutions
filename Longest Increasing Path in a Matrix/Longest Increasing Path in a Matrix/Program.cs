Console.WriteLine(longestIncreasingPath(new int[,] { { 9, 9, 4}, { 6,6,8}, { 2,1,1} })); // 4
Console.WriteLine(longestIncreasingPath(new int[,] { { 3, 4, 5 }, { 3, 2, 6 }, { 2, 2, 1 } })); // 4
Console.WriteLine(longestIncreasingPath(new int[,] { { 1 } })); // 1

/*
 * Memoization approach
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 */
int longestIncreasingPath(int[,] matrix)
{
    int[,] dp = new int[matrix.GetLength(0), matrix.GetLength(1)];

    int maxValue = 1;

    for (int i = 0; i < matrix.GetLength(0); i++)
    {
        for (int j = 0; j < matrix.GetLength(1); j++)
        {
            maxValue = Math.Max(maxValue, dfs(i, j, matrix, int.MinValue, dp));
        }
    }

    return maxValue;
}

int dfs(int i, int j, int[,] matrix, int prev, int[,] dp)
{
    int maxValue = 1;

    if (i < 0 || j < 0 || i >= matrix.GetLength(0) || j >= matrix.GetLength(1) || prev >= matrix[i, j])
        return 0;

    if (dp[i, j] != 0)
        return dp[i, j];

    maxValue = Math.Max(maxValue, dfs(i, j + 1, matrix, matrix[i, j], dp) + 1); // right
    maxValue = Math.Max(maxValue, dfs(i + 1, j, matrix, matrix[i, j], dp) + 1); // down
    maxValue = Math.Max(maxValue, dfs(i, j - 1, matrix, matrix[i, j], dp) + 1); // left
    maxValue = Math.Max(maxValue, dfs(i - 1, j, matrix, matrix[i, j], dp) + 1); // up

    return dp[i, j] = maxValue;
}

/*
 * Bruteforce appraoch
 * Time Complexity: O(4^n)
 * Space Complexity: O(n)
 */
/*
int longestIncreasingPath(int[,] matrix)
{
    int maxValue = 1;

    for (int i = 0; i < matrix.GetLength(0); i++)
    {
        for (int j = 0; j < matrix.GetLength(1); j++)
        {
            maxValue = Math.Max(maxValue, dfs(i, j, matrix, int.MinValue));
        }
    }

    return maxValue;
}


int dfs(int i, int j, int[,] matrix, int prev)
{
    int maxValue = 1;

    if (i < 0 || j < 0 || i >= matrix.GetLength(0) || j >= matrix.GetLength(1) || prev >= matrix[i, j])
        return 0;

    maxValue = Math.Max(maxValue, dfs(i, j + 1, matrix, matrix[i, j]) + 1); // right
    maxValue = Math.Max(maxValue, dfs(i + 1, j, matrix, matrix[i, j]) + 1); // down
    maxValue = Math.Max(maxValue, dfs(i, j - 1, matrix, matrix[i, j]) + 1); // left
    maxValue = Math.Max(maxValue, dfs(i - 1, j, matrix, matrix[i, j]) + 1); // up

    return maxValue;
}
*/