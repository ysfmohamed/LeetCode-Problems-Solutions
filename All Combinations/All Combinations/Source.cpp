#include<iostream>
#include<vector>
using namespace std;

/*
* This problem is an extended version of the Combination Sum problem (#39) in which we output all combinations not just the unique combinations.
*/

/*
* Bruteforce
* m = target
* Time Complexity: O(m^n)
* Space Complexity (without considering auxiliary space): O(m)
*/
void combinationSumHelper(vector<int> candidates, int target, vector<int>& singleComb, vector<vector<int>>& allCombinations)
{
	if (target == 0)
	{
		allCombinations.push_back(singleComb);
		return;
	}

	for (int i = 0; i < candidates.size(); i++)
	{
		int remaining = target - candidates[i];
		if (remaining >= 0)
		{
			singleComb.push_back(candidates[i]);
			combinationSumHelper(candidates, remaining, singleComb, allCombinations);
			singleComb.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
	vector<vector<int>> allCombinations;
	vector<int> singleComb;

	combinationSumHelper(candidates, target, singleComb, allCombinations);

	return allCombinations;
}

int main()
{
	for (auto arr : combinationSum({ 2, 3, 6, 7 }, 7))
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}

		cout << endl;
	} // [ [2, 2, 3], [2, 3, 2], [3, 2, 2]. [7] ]

	cout << endl;
	cout << endl;

	for (auto arr : combinationSum({ 2, 3, 5 }, 8))
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}

		cout << endl;
	} // [ [2, 2, 2, 2], [2, 3, 3], [3, 2, 3], [3, 3, 2], [3, 5], [5, 3] ]

	cout << endl;
	cout << endl;

	for (auto arr : combinationSum({ 2 }, 1))
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}

		cout << endl;
	} // []

	return 0;
}
