/*
 * Problem number: 70
 * Difficulty: easy
 */
int climbStairs(int n)
{
    /*
	 * Time Complexity: O(n)
	 * Space Complexity: O(n)
	 */
    int[] table = new int[n + 1];

    table[0] = 0;
    table[1] = 1;

    if (n >= 2)
    {
        table[2] = 2;

        for (int i = 3; i <= n; i++)
            table[i] = table[i - 2] + table[i - 1];
    }

    return table[n];

    //Dictionary<int, int> memo = new Dictionary<int, int>();

    //return climbStairsHelper(n, memo);
}

/*int climbStairsHelper(int n, Dictionary<int, int> memo)
{
	if (memo.ContainsKey(n))
		return memo[n];
	if (n == 0)
		return memo[n] = 1;
	if (n < 0)
		return memo[n] = 0;

	return memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
}*/

/*
 * Bruteforce Approach
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
*/
/*int climbStairsHelper(int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;

	return climbStairsHelper(n - 1) + climbStairsHelper(n - 2);
}*/