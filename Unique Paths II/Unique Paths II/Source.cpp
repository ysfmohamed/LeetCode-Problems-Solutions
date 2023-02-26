#include<iostream>
#include<vector>
using namespace std;

/*
* Problem Number: #63
* Problem Difficulty: Medium
*/

/*
* Bruteforce solution
* Time Complexity: O(2^(n+m))
* Space Complexity: O(n+m) for call stack
*/
int uniquePathsHelper(int i, int j, vector<vector<int>> obstacleGrid)
{
	if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1)
		return 0;

	if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
		return 1;

	return uniquePathsHelper(i + 1, j, obstacleGrid) + uniquePathsHelper(i, j + 1, obstacleGrid);
}

/*
* Memoized solution
* Time Complexity: O(nm)
* Space Complexity: O(n+m) for call stack and O(nm) for cache
*/
int uniquePathsHelper(int i, int j, vector<vector<int>> obstacleGrid, vector<vector<int>>& dp)
{
	if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
		return 1;

	return dp[i][j] = uniquePathsHelper(i + 1, j, obstacleGrid, dp) + uniquePathsHelper(i, j + 1, obstacleGrid, dp);
}

int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
{
	vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

	return uniquePathsHelper(0, 0, obstacleGrid, dp);
}

int main()
{
	cout << uniquePathsWithObstacles({ {0,0,0}, {0,1,0}, {0,0,0} }) << endl; // 2
	cout << uniquePathsWithObstacles({ {0,1}, {0,0} }) << endl; // 1
	return 0;
}