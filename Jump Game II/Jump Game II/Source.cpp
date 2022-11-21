#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
* Problem number: 45
* Difficulty: Medium
*/


/*
* Bruteforce
* Time Complexity: O(m^n)
* Space complexity: O(n)
*/
int jumpHelper(vector<int> nums, int index)
{
	if (index >= nums.size())
		return INT_MAX;

	if (index == nums.size() - 1)
		return 0;

	if (index != nums.size() - 1 && nums[index] == 0)
		return INT_MAX;

	int minJump = INT_MAX;

	for (int i = 1; i <= nums[index]; i++)
	{
		int ret = jumpHelper(nums, index + i);

		if (ret != INT_MAX)
			minJump = min(minJump, ret + 1);
	}

	return minJump;
}

int jump(vector<int> nums)
{
	//vector<int> dp(nums.size(), -1);

	// If it returns INT_MAX it means there is no way to reach to end (It is not required in the original problem).
	//return jumpHelper(nums, 0);

	/*
	* Tabulation
	* Time Complexity: O(n^2)
	* Space Complexity: O(n)
	*/

	if (nums.size() == 1)
		return 0;
	
	if (nums[0] == 0)
		return 0;

	vector<int> dp(nums.size(), INT_MAX);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 1; j <= nums[i]; j++)
		{
			if (i + j < nums.size())
				dp[i+j] = min(dp[i] + 1, dp[i + j]);
		}
	}

	return dp[nums.size() - 1];
}

int main()
{
	cout << jump({2, 3, 1, 1, 4}) << endl; // 2

	cout << jump({ 2, 3, 0, 1, 4 }) << endl; // 2

	cout << jump({ 1 }) << endl; // 0

	cout << jump({ 1, 3, 2 }) << endl; // 2

	cout << jump({ 1, 3, 2, 1, 2, 2, 1, 2 }) << endl; // 4

	cout << jump({ 1, 3, 2, 1, 2 }) << endl; // 2

	cout << jump({ 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 }) << endl; // 3

	return 0;
}