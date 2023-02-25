#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
* Problem Number: #62
* Problem Difficulty: Medium
*/


/* Bruteforce solution
* Time Complexity: O(2^(n+m))
* Space Complexity: O(n+m)
*/
int uniquePathsHelper(int m, int n, int i, int j)
{
	if (i >= m || j >= n)
		return 0;

	if (i == m - 1 && j == n - 1)
		return 1;

	return uniquePathsHelper(m, n, i + 1, j) + uniquePathsHelper(m, n, i, j + 1);
}

// Memoized solution using map
int uniquePathsHelper(int m, int n, int i, int j, map<pair<int, int>, int>& dp)
{
	if (i >= m || j >= n)
		return 0;

	if (dp.find(make_pair(i, j)) != dp.end())
		return dp[make_pair(i, j)];

	if (i == m - 1 && j == n - 1)
		return 1;

	return dp[make_pair(i, j)] = uniquePathsHelper(m, n, i + 1, j, dp) + uniquePathsHelper(m, n, i, j + 1, dp);
}

/*
* Memoized solution using 2D vector
* Time Complexity: O(nm)
* Space Complexity: O(n+m) for call stack and O(nm) for cache
*/
int uniquePathsHelper(int m, int n, int i, int j, vector<vector<int>>& dp)
{
	if (i >= m || j >= n)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == m - 1 && j == n - 1)
		return 1;

	return dp [i][j] = uniquePathsHelper(m, n, i + 1, j, dp) + uniquePathsHelper(m, n, i, j + 1, dp);
}

int uniquePaths(int m, int n)
{
	//map<pair<int, int>, int> dp;

	vector<vector<int>> dp(m, vector<int>(n, -1));

	return uniquePathsHelper(m, n, 0, 0, dp);
}

int main()
{
	cout << uniquePaths(3, 7) << endl; // 28
	cout << uniquePaths(3, 2) << endl; // 3
	cout << uniquePaths(9, 9) << endl; // 12870
	cout << uniquePaths(10, 10) << endl; // 48620
	cout << uniquePaths(20, 20) << endl; // 48620

	return 0;
}