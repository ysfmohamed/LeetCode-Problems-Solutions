#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
* Problem Number: #980
* Problem Difficulty: Hard
*/


/*
* Bruteforce solution
* Time Complexity: O(4^(n+m)) * O(logn)
* Space Comlexity: O(n + m) for call stack;
* 
* NOTE: it could be solved in just O(4^(n+m)) with 2D Vector for saving visited vertices
*/
int uniquePathsHelper(int i, int j, vector<vector<int>> grid, int numOfClearTiles, map<pair<int, int>, bool>& visited)
{
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() )
		return 0;

	if (visited[make_pair(i, j)] == true || grid[i][j] == -1)
		return 0;

	if (grid[i][j] == 2)
	{
		if (numOfClearTiles == 0)
			return 1;

		else
			return 0;
	}

	visited[make_pair(i, j)] = true;
	numOfClearTiles--;

	int totalCount = 
		uniquePathsHelper(i - 1, j, grid, numOfClearTiles, visited) +
		uniquePathsHelper(i, j + 1, grid, numOfClearTiles, visited) + 
		uniquePathsHelper(i + 1, j, grid, numOfClearTiles, visited) + 
		uniquePathsHelper(i, j - 1, grid, numOfClearTiles, visited);

	visited[make_pair(i, j)] = false;

	return totalCount;
}

int uniquePaths(vector<vector<int>> grid)
{
	pair<int, int> startingPosition;
	int numOfClearTiles = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 0 || grid[i][j] == 2)
				numOfClearTiles++;

			else if (grid[i][j] == 1)
			{
				startingPosition.first = i;
				startingPosition.second = j;
			}
		}
	}

	map<pair<int, int>, bool> visited;

	return uniquePathsHelper(startingPosition.first, startingPosition.second, grid, numOfClearTiles, visited);
}

int main()
{
	cout << uniquePaths({ {1,0,0,0}, {0,0,0,0}, {0,0,2,-1} }) << endl; // 2
	cout << uniquePaths({ {1,0,0,0}, {0,0,0,0}, {0,0,0,2} }) << endl; // 4
	cout << uniquePaths({ {0,1}, {2,0} }) << endl; // 0

	return 0;
}