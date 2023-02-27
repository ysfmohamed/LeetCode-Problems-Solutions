#include<iostream>
#include<vector>
using namespace std;

/*
* Problem Number: #216
* Problem Difficulty: Medium
*/


/*
* Bruteforce Solution
* m = target
* Time Complexity: O(2^m)
* Space Complexity: O(m) for call stack
*/
void combinationSumHelper(int currentIndex, int k, int target, vector<int> nums, vector<int>& singlePath, vector<vector<int>>& combinations)
{
	if (target == 0)
	{
		if (singlePath.size() == k)
			combinations.push_back(singlePath);
		return;
	}

	if (currentIndex >= nums.size())
		return;

	if (target >= nums[currentIndex])
	{
		singlePath.push_back(nums[currentIndex]);
		combinationSumHelper(currentIndex + 1, k, target - nums[currentIndex], nums, singlePath, combinations);
		singlePath.pop_back();
	}

	combinationSumHelper(currentIndex + 1, k, target, nums, singlePath, combinations);
}

vector<vector<int>> combinationSum(int k, int n)
{
	vector<int> singlePath;
	vector<vector<int>> combinations;

	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };

	combinationSumHelper(0, k, n, nums, singlePath, combinations);

	return combinations;
}

void output(vector<vector<int>> nums)
{
	cout << "[" << endl;
	for (auto arr : nums)
	{
		cout << "    [";
		for (auto num : arr)
		{
			cout << "  " << num << " ";
		}

		cout << "]" << endl;
	}
	cout << "]" << endl;

	cout << "############## END ##############" << endl;
}

int main()
{
	vector<vector<int>> solution;

	solution = combinationSum(3, 7);
	output(solution);

	solution = combinationSum(3, 9);
	output(solution);

	solution = combinationSum(4, 1);
	output(solution);

	solution = combinationSum(9, 45);
	output(solution);

	return 0;
}