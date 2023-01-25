#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

/*
* n = rows = nums.size()
* m = cols = nums[i].size()

* Bruteforce function:
* 1- Time complexity: O(2^n).
* 2- Space Complexity: O(n) for call stack.

* Memoization function:
* 1- Time Complexity: # of subproblems * time/subproblem = (n+m) * O(log(n+m)) = O((n+m)*log(n+m)).
* Note: time/subproblem is O(log(n+m)) because we are using map data structure (self-balancing binary tree).
* 2- Space Complexity: O(n+m) for map data structure and O(n) or call stack.
 
* Generate all possible solutions function:
* 1- Time Complexity: O(2^n).
* 2- Space Complexity:
*	O(2^n) for storing all possible paths (allPath 2D vector).
*	O(n) for storing only one single path (singlePath 1D vector).
*   O(n) for the call stack.
*/

// Memoization
int longestSlideDownHelper(vector<vector<int>> nums, int i, int j, map<pair<int, int>, int>& dp)
{
	if (i >= nums.size() || j >= nums[i].size())
		return 0;

	if (dp.find(make_pair(i,j)) != dp.end())
		return dp[make_pair(i, j)];

	return dp[make_pair(i, j)] = max(nums[i][j] + longestSlideDownHelper(nums, i + 1, j, dp), nums[i][j] + longestSlideDownHelper(nums, i + 1, j + 1, dp));
}

// Bruteforce
int longestSlideDownHelper(vector<vector<int>> nums, int i, int j)
{
	if (i >= nums.size() || j >= nums[i].size())
		return 0;

	return max(nums[i][j] + longestSlideDownHelper(nums, i + 1, j), nums[i][j] + longestSlideDownHelper(nums, i + 1, j + 1));
}

// Generate all possible paths
int longestSlideDownHelper(vector<vector<int>> nums, int i, int j, vector<vector<int>>& allPaths, vector<int>& singlePath)
{
	if (i >= nums.size() || j >= nums[i].size())
		return 0;

	singlePath.push_back(nums[i][j]);

	int first = nums[i][j] + longestSlideDownHelper(nums, i + 1, j, allPaths, singlePath);
	int second = nums[i][j] + longestSlideDownHelper(nums, i + 1, j + 1, allPaths, singlePath);

	// To be sure that we are adding only the full path (path from the top of the pyramid to all way down).
	if (singlePath.size() == nums.size())
		allPaths.push_back(singlePath);

	singlePath.pop_back();

	return max(first, second);
}

int longestSlideDown(vector<vector<int>> nums)
{
	map<pair<int, int>, int> dp;

	vector<int> singlePath;
	vector<vector<int>> allPaths;

	// Call memoization function
	int res = longestSlideDownHelper(nums, 0, 0, dp);

	// Call bruteforce function
	// int res = longestSlideDownHelper(nums, 0, 0);

	// Call the function that generates all the possible solutions
	//int res = longestSlideDownHelper(nums, 0, 0, allPaths, singlePath);

	for (auto arr : allPaths)
	{
		for (auto num : arr)
			cout << num << " ";
		cout << endl;
	}

	return res;
}

int main()
{
	cout << longestSlideDown({ { 3 } }) << endl; // 3

	cout << longestSlideDown(
		{
			{ 3 },
			{7, 4},
			{2, 4, 6},
			{8, 5, 9, 3}
		}
	) << endl; // 23

	cout << longestSlideDown(
		{ 
			{ 3 }, 
			{ 7, 4 }, 
			{ 2, 4, 6 }, 
			{ 8, 5, 9, 3 }, 
			{10, 5, 7, 6, 20} 
		}
	) << endl; // 36

	cout << longestSlideDown(
		{ 
			{ 3 }, 
			{ 7, 4 }, 
			{ 2, 4, 6 }, 
			{ 8, 5, 9, 3 }, 
			{10, 5, 7, 6, 20}, 
			{23, 5, 15, 6, 20, 3}, 
			{16, 5, 25, 6, 10, 3, 12},  
			{16, 5, 25, 6, 10, 3, 12, 22}, 
			{16, 5, 25, 6, 10, 3, 12, 22, 5}, 
			{16, 5, 25, 6, 10, 3, 12, 22, 5, 8}, 
			{16, 5, 25, 6, 10, 3, 12, 22, 5, 8, 11}, 
			{16, 5, 25, 6, 10, 3, 12, 22, 5, 8, 11, 4}, 
			{16, 5, 25, 6, 10, 3, 12, 22, 5, 8, 11, 4, 1},  
			{16, 5, 25, 6, 10, 3, 12, 22, 5, 8, 11, 4, 1, 99} 
		}) << endl; // 245

	cout << longestSlideDown(
		{	{75},
			{95, 64},
			{17, 47, 82},
			{18, 35, 87, 10},
			{20, 4, 82, 47, 65},
			{19, 1, 23, 75, 3, 34},
			{88, 2, 77, 73, 7, 63, 67},
			{99, 65, 4, 28, 6, 16, 70, 92},
			{41, 41, 26, 56, 83, 40, 80, 70, 33},
			{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
			{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
			{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
			{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
			{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
			{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
		}
	) << endl; // 1074

	return 0;
}