/*
 * Problem number: 121
 * Difficulty: Easy
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int maxProfit(int[] prices)
{
	int pricesSize = prices.Length + 1;

	int[] table = new int[prices.Length + 1];

	table[0] = 0;
	table[1] = 0;

	if (prices.Length >= 2)
	{
		table[2] = prices[1] > prices[0] ? prices[1] - prices[0] : 0;
		int tempMin = Math.Min(prices[0], prices[1]);

		for (int i = 3; i <= prices.Length; i++)
		{
			tempMin = Math.Min(tempMin, prices[i - 1]);
			table[i] = Math.Max(table[i - 1], prices[i - 1] - tempMin);
		}
	}

	return table[pricesSize];
}