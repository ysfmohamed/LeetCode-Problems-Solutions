/*
 * Problem number: 64
 * Difficulty: Medium
 * 
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 */
int minPathSum(int[,] grid)
{
	int rows = grid.GetLength(0);
	int cols = grid.GetLength(1);

	int[,] table = new int[rows + 1, cols+1];

	table[1,1] = grid[0,0];
	
	for (int i = 2; i <= cols; i++)
		table[1,i] = table[1,i - 1] + grid[0,i - 1];
	
	for (int i = 2; i <= rows; i++)
		table[i,1] = table[i - 1,1] + grid[i - 1,0];
	
	for (int i = 2; i <= rows; i++)
	{
		for (int j = 2; j <= cols; j++)
		{
			table[i,j] = grid[i - 1,j - 1] + Math.Min(table[i - 1,j], table[i,j - 1]);
		}
	}
	
	return table[rows,cols];
}