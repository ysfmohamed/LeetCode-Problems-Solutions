#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* Problem number: 377
* Difficulty: Medium
*/

/*
* Bruteforce
* m = target
* Time Complexity: O(m^n)
* Space Complexity: O(m)
*/
int combSumHelper2(vector<int> nums, int  target)
{
	if (target == 0)
		return 1;

	if (target < 0)
		return 0;

	int ways = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		ways += combSumHelper2(nums, target - nums[i]);
	}

	return ways;
}

/*
* Memoization
*/
long combSumHelper(vector<int> nums, int  target, unordered_map<long, long>& dp)
{
	if (dp.find(target) != dp.end())
		return dp[target];

	if (target == 0)
		return 1;

	if (target < 0)
		return 0;

	long ways = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		ways += combSumHelper(nums, target - nums[i], dp);
		dp[target] = ways;
	}

	return dp[target];
}

int combinationSum(vector<int> nums, int target)
{
	unordered_map<long, long> dp;
	return combSumHelper(nums, target, dp);
}

int main()
{
	cout << combinationSum({1, 2, 3}, 4) << endl; // 7

	cout << combinationSum({ 9 }, 3) << endl; // 0

	return 0;
}