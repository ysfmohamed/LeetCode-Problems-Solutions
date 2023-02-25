#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
* Problem Number: #40
* Problem Difficulty: Medium
*/

/*
* Bruteforce solution:
*	n = candidates.size()
* 
*	Time Complexity: O(2^n)
*	Space Comxplexity: the most longest combination = O(n)
*					   O(2^n) for all combinations
*                      O(n) for every combination
*/

void combinationSumHelper(int i, int currentSum, vector<int> candidates, int target, vector<int>& singlePath, vector<vector<int>>& combinations)
{
	if (currentSum == target)
	{
		//if (!(find(combinations.begin(), combinations.end(), singlePath) != combinations.end()))
		combinations.push_back(singlePath);
		return;
	}

	if (i == candidates.size())
	{
		return;
	}

	if (currentSum > target)
		return;

	singlePath.push_back(candidates[i]);
	combinationSumHelper(i + 1, currentSum + candidates[i], candidates, target, singlePath, combinations);
	singlePath.pop_back();

	for (; i < candidates.size() - 1;)
	{
		if (candidates[i] == candidates[i + 1])
			i++;

		else
			break;
	}

	combinationSumHelper(i + 1, currentSum, candidates, target, singlePath, combinations);
}

vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
	vector<int> singlePath;
	vector<vector<int>> combinations;

	sort(candidates.begin(), candidates.end());

	combinationSumHelper(0, 0, candidates, target, singlePath, combinations);

	return combinations;
}

void output(vector<vector<int>> nums)
{
	cout << "[" << endl;
	for (auto arr: nums)
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
	solution = combinationSum({ 1, 2, 6, 1, 5 }, 8);
	output(solution);

	solution = combinationSum({ 10,1,2,7,6,1,5 }, 8);
	output(solution);

	solution = combinationSum({ 2,5,2,1,2 }, 5);
	output(solution);

	return 0;
}