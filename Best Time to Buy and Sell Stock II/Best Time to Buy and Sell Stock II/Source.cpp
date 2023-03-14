#include<iostream>
#include<vector>
using namespace std;

/*
* Problem Number: #122
* Problem Difficulty: Medium
*/

/*
* Bruteforce Solution
* n = prices.size()
* Time Complexity: O(2^n)
* Space Complexity: O(n)
*/
int maxProfitHelper(int i, bool buy, vector<int> prices)
{
	if (i >= prices.size())
		return 0;

	int profit = 0;

	if(buy)
	{
		int buyThatDay = -prices[i] + maxProfitHelper(i + 1, false, prices);
		int skipThatDay = maxProfitHelper(i + 1, true, prices);
		profit = max(buyThatDay, skipThatDay);
	}
	else
	{
		int sellThatDay = prices[i] + maxProfitHelper(i + 1, true, prices);
		int skipThatDay = maxProfitHelper(i + 1, false, prices);
		profit = max(sellThatDay, skipThatDay);
	}

	return profit;
}

/*
* Memoized Solution
* n = prices.size()
* Time Complexity: O(2n) = O(n)
* Space Complexity: O(2n) = O(n)
*/
int maxProfitHelper(int i, bool buy, vector<int> prices, vector<vector<int>>& dp)
{
	if (i >= prices.size())
		return 0;

	if (dp[i][buy] != -1)
		return dp[i][buy];

	int profit = 0;

	if (buy)
	{
		int buyThatDay = -prices[i] + maxProfitHelper(i + 1, false, prices, dp);
		int skipThatDay = maxProfitHelper(i + 1, true, prices, dp); // Don't buy that day
		profit = max(buyThatDay, skipThatDay);
	}
	else
	{
		int sellThatDay = prices[i] + maxProfitHelper(i + 1, true, prices, dp);
		int skipThatDay = maxProfitHelper(i + 1, false, prices, dp); // Don't sell that day
		profit = max(sellThatDay, skipThatDay);
	}

	dp[i][buy] = profit;

	return dp[i][buy];
}

/*
* Tabulation Solution
* n = prices.size()
* Time Complexity: O(2n) = O(n)
* Space Complexity: O(2n) = O(n)
*/
/*
int maxProfitHelperG(vector<int> prices)
{
	vector<vector<int>> dp(prices.size() + 1, vector<int>(2));

	dp[0][0] = 0; dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = -prices[0];

	for (int i = 2; i < dp.size(); i++)
	{
		for (int buy = 0; buy < 2; buy++)
		{
			if (buy)
			{
				dp[i][buy] = max(-prices[i - 1] + dp[i - 1][0], dp[i - 1][1]);
			}
			else
			{
				dp[i][buy] = max(prices[i - 1] + dp[i - 1][1], dp[i - 1][0]);
			}
		}
	}

	return max(dp[prices.size()][0], dp[prices.size()][1]);
}
*/

/*
* Greedy Solution
* Time Complexity: O(n)
* Space Complexity: O(1)
*/
int maxProfitHelper(vector<int> prices)
{
	int maxProfit = 0;
	int buy = prices[0];

	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (prices[i] < prices[i + 1])
		{
			if (i == prices.size() - 2)
			{
				maxProfit += prices[i + 1] - buy;
			}
			continue;
		}
		else {
			maxProfit = maxProfit + prices[i] - buy;
			buy = prices[i+1];
		}
	}

	return maxProfit;
}

int maxProfit(vector<int> prices)
{
	vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
	return maxProfitHelper(0, true, prices, dp);
}

int main()
{
	cout << maxProfit({ 7,1,5,3,6,4 }) << endl; // 7
	cout << maxProfit({ 1,2,3,4,5 }) << endl; // 4
	cout << maxProfit({ 7,6,4,3,1 }) << endl; // 0

	return 0;
}