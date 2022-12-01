#include<iostream>
#include<vector>
using namespace std;

/*
* Problem number: #39
* Difficulty: Medium
*/

/*
* Bruteforce
* t = target
* Time Complexity: O(2^t)
* Space Complexity (without considering auxiliary space): O(t)
*/
void combinationSumHelper(int currIndex, vector<int> candidates, int target, vector<int>& singleComb, vector<vector<int>>& uniqueCombs)
{
	if (currIndex >= candidates.size())
		return;

	if (target == 0)
	{
		uniqueCombs.push_back(singleComb);
		return;
	}

	if (target >= candidates[currIndex])
	{
		singleComb.push_back(candidates[currIndex]);
		combinationSumHelper(currIndex, candidates, target - candidates[currIndex], singleComb, uniqueCombs);
		singleComb.pop_back();
	}
	combinationSumHelper(currIndex + 1, candidates, target, singleComb, uniqueCombs);
}

vector<vector<int>> combinationSum(vector<int> candidates, int target) 
{
	vector<vector<int>> uniqueCombs;
	vector<int> singleComb;

	combinationSumHelper(0, candidates, target, singleComb, uniqueCombs);

	return uniqueCombs;
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
	}

	cout << endl;
	cout << endl;

	for (auto arr : combinationSum({ 2, 3, 5 }, 8))
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}

		cout << endl;
	}

	cout << endl;
	cout << endl;

	for (auto arr : combinationSum({ 2 }, 1))
	{
		for (auto num : arr)
		{
			cout << num << " ";
		}

		cout << endl;
	}
	return 0;
}
