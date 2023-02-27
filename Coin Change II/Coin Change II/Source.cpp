#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
* Problem Number: #518
* Problem Difficulty: Medium
*/

/*
* Bruteforce Solution
* k = amount
* Time Comlexity: O(2^k)
* Space Complexity: O(k)
*/
int changeHelper(int currentIndex, int amount, vector<int> coins)
{
	int combinations = 0;

	if (currentIndex >= coins.size())
		return 0;

	if (amount == 0)
		return 1;

	if (amount >= coins[currentIndex])
	{
		combinations += changeHelper(currentIndex, amount - coins[currentIndex], coins);
	}

	combinations += changeHelper(currentIndex + 1, amount, coins);

	return combinations;
}

/*
* Memoized Solution
* NOTE: it could be solved using 2D vector cache
*/
int changeHelper(int currentIndex, int amount, vector<int> coins, map<pair<int,int>, int>& dp)
{
	int combinations = 0;

	if (currentIndex >= coins.size())
		return 0;

	if (dp.find(make_pair(currentIndex, amount)) != dp.end())
		return dp[make_pair(currentIndex, amount)];

	if (amount == 0)
		return 1;

	if (amount >= coins[currentIndex])
	{
		combinations += changeHelper(currentIndex, amount - coins[currentIndex], coins, dp);
		dp[make_pair(currentIndex, amount)] = combinations;
	}

	combinations += changeHelper(currentIndex + 1, amount, coins, dp);
	dp[make_pair(currentIndex, amount)] = combinations;

	return combinations;
}

int change(int amount, vector<int> coins)
{
	map<pair<int, int>, int> dp;

	return changeHelper(0, amount, coins, dp);
}

int main()
{
	cout << change(5, {1, 2, 5}) << endl; // 4
	cout << change(3, { 2 }) << endl; // 0
	cout << change(10, { 10 }) << endl; // 1

	return 0;
}