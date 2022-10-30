#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
* Problem number: 200
* Difficulty: Medium
*/


/*
* Time Complexity: O(nm)
* Space Complexity: O(nm)
*/

// DFS solution
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

// BFS solution
void bfs(vector<vector<char>>& grid, int i, int j)
{
	int rowBound = grid.size(), colBound = grid[0].size();
	pair<int, int> current;

	grid[i][j] = '0';
	queue<pair<int, int>> queue;
	queue.push({i, j});

	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		// Now we must explore its neighbours (up - left - down - right)
		int r = current.first, c = current.second;
		if (r - 1 >= 0 && r - 1 < rowBound && c >= 0 && c < colBound && grid[r - 1][c] == '1')
		{
			grid[r - 1][c] = '0';
			queue.push({r-1, c});
		}
		if (r + 1 >= 0 && r + 1 < rowBound && c >= 0 && c < colBound && grid[r + 1][c] == '1')
		{
			grid[r + 1][c] = '0';
			queue.push({ r + 1, c });
		}
		if (r >= 0 && r < rowBound && c - 1 >= 0 && c - 1 < colBound && grid[r][c - 1] == '1')
		{
			grid[r][c - 1] = '0';
			queue.push({ r, c - 1});
		}
		if (r >= 0 && r < rowBound && c + 1 >= 0 && c + 1 < colBound && grid[r][c + 1] == '1')
		{
			grid[r][c + 1] = '0';
			queue.push({ r, c + 1 });
		}
	}
}

int numIslands(vector<vector<char>> grid)
{
	int count = 0;
	/*
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (dfs(grid, i, j))
				count++;
		}
	}
	*/

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				count++;
				bfs(grid, i, j);
			}
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