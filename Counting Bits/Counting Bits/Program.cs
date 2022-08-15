/*
 * Problem number: 338
 * Difficulty: Easy
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int[] countBits(int n)
{
	int[] table = new int [n +1];
	
	if (n == 0)
	{
		return table;
	}
	else if (n == 1)
	{
		table[0] = 0;
		table[1] = 1;
		return table;
	}
	else if (n == 2)
	{
		table[0] = 0;
		table[1] = 1;
		table[2] = 1;
		return table;
	}
	
	table[0] = 0;
	table[1] = 1;
	table[2] = 1;
	
	if (n >= 3)
	{
		for (int i = 3; i <= n; i++)
		{
			if (i % 2 == 0)
				table[i] = table[i / 2];
	
			else if (i % 2 != 0)
				table[i] = table[i / 2] + table[2];
		}
	}
	
	return table;
}