#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

/*
* Problem number: 200
* Difficulty: Medium
*/


/*
* Time Complexity: O(nm)
* Space Complexity: O(nm)
*/
bool dfs(vector<vector<char>>& grid, int i, int j)
{
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
		return false;

	grid[i][j] = '0';
	dfs(grid, i - 1, j);
	dfs(grid, i + 1, j);
	dfs(grid, i, j - 1);
	dfs(grid, i, j + 1);
	
	return true;
}

int numIslands(vector<vector<char>> grid)
{
	int count = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (dfs(grid, i, j))
				count++;
		}
	}

	return count;
}

int main()
{
	cout << numIslands({ {'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'} }) << endl; // 1

	cout << numIslands({ {'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'} }) << endl; // 3
	return 0;
}