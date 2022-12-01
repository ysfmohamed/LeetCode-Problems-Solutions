#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* Bruteforce
* Time Complexity: O(2^n)
* Space Complexity: O(n)
*/
//int maxCandiesHelper(vector<int> nums, int i)
//{
//	if (i >= nums.size())
//		return 0;
//
//	int path1 = nums[i] + maxCandiesHelper(nums, i + 2);
//	int path2 = nums[i] + maxCandiesHelper(nums, i + 3);
//
//	return max(path1, path2);
//}

int maxCandiesHelper(vector<int> nums, int i, unordered_map<int,int>& dp)
{
	if (i >= nums.size())
		return 0;

	if (dp.find(i) != dp.end())
		return dp[i];

	int path1 = nums[i] + maxCandiesHelper(nums, i + 2, dp);
	int path2 = nums[i] + maxCandiesHelper(nums, i + 3, dp);

	return dp[i] = max(path1, path2);
}

int maxCandies(vector<int> nums)
{
	unordered_map<int, int> dp;
	return maxCandiesHelper(nums, 0, dp);
}

int main()
{
	cout << maxCandies({11, 5, 3, 17, 2, 13, 9, 7}) << endl; // 48

	cout << maxCandies({ 9, 7, 12, 7, 16, 3, 7, 17, 14, 13, 4, 6, 11, 6, 3, 3, 5, 4, 11, 3, 15, 12, 14, 2, 15, 19, 11, 12, }) << endl; // 157

	cout << maxCandies({ 9, 7, 12, 7, 16, 3, 7, 17, 14, 13, 4, 6, 11, 6, 3, 3, 5, 4, 11, 3, 15, 12, 14, 2, 15, 19, 11, 12, 12, 7, 16, 3, 7, 17, 14, 6, 3, 3, 5, 4, 11, 3, 15, 12, 14, 5, 3, 17, 2, 13, 9, 7, 13, 4, 6, 11, 6, 3, 3, 5, 4, 11, 3, 15, 12, 14, 2, 15, 19, 11, 12, 12, 7, 16, 3, 7, 17, 14, 6, 3, 3, 5, 4, 11, 3, 15, 12}) << endl; // 460
	
	return 0;
}