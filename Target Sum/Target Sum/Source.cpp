#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

/*
* Problem number: 494
* Difficulty: Medium
*/


/*
* Bruteforce
* Time Comxplexity: O(2^n)
* Space Complexity: O(n)
*/
int targetSum2(vector<int> nums, int index, int currentTotal, int target)
{
	if (index >= nums.size())
		return 0;

	int path1 = nums[index] + currentTotal;
	int path2 = -nums[index] + currentTotal;


	int ways = 0;
	ways += targetSum2(nums, index + 1, path1, target);
	ways += targetSum2(nums, index + 1, path2, target);


	if ((path1 == target || path2 == target) && index == nums.size() - 1)
		ways++;

	return ways;
}

int targetSum(vector<int> nums, int index, int currentTotal, int target, map<pair<int, int>, int>& dp)
{
	if (index >= nums.size())
	{
		if (currentTotal == target)
			return 1;
		else
			return 0;
	}

	if (dp.find({ index, currentTotal}) != dp.end())
		return dp[{index, currentTotal}];

	int path1 = nums[index] + currentTotal;
	int path2 = -nums[index] + currentTotal;


	dp[{index, currentTotal}] = targetSum(nums, index + 1, path1, target, dp) + targetSum(nums, index + 1, path2, target, dp);

	return dp[{index, currentTotal}];
}

int findTargetSumWays(vector<int> nums, int target)
{
	map<pair<int, int>, int> dp;
	return targetSum(nums, 0, 0, target, dp);
}


int main()
{
	cout << findTargetSumWays({1, 1, 1, 1, 1}, 3) << endl; // 5
	cout << findTargetSumWays({ 1, 2, 3}, 0) << endl; // 2

	return 0;
}