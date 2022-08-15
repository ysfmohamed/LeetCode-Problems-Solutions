/*
 * Problem number: 746
 * Difficulty: Easy
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int minCostClimbingStairs(int[] cost)
{
	int[] table = new int[cost.Length + 1];

	table[2] = Math.Min(cost[0], cost[1]);
	
	for (int i = 3; i <= cost.Length; i++)
	{
		table[i] = Math.Min(table[i - 2] + cost[i - 2], table[i - 1] + cost[i - 1]);
	}
	
	return table[cost.Length];
}