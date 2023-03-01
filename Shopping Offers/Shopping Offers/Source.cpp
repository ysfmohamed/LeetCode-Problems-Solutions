#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
* Problem Number: #638
* Problem Difficulty: Medium
*/

/*
* Every call we have many decisions to take
* 
* For the first test case:
* we have 3 decisions in each call, we can buy with the original price or with the first offer or with the second offer
* So, if the special 2D vector size is "m" so we have "m + 1" decisions to take in each call, and that 1 for buying with the original price.
* 
* n = needs.size();
* height tree = if the one of the special offers contains only ones [1, 1, .... 1]
* so in every call elements of needs vector will be subtracted by 1.
* height tree = needs[0] (assuming all elements of needs are equal).
* height tree = k
* 
* Time Complexity: O(m^k * n^4)
*/

int checkNeeds(vector<int> needs)
{
	for (int i = 0; i < needs.size(); i++)
	{
		if (needs[i] != 0)
			return false;
	}

	return true;
}

int checkNeedsFitOffers(vector<int> special, vector<int>& needs)
{
	for (int i = 0; i < needs.size(); i++)
	{
		if (special[i] > needs[i])
			return false;
	}

	return true;
}

void consumeOffer(vector<int> special, vector<int>& needs)
{
	for (int i = 0; i < needs.size(); i++)
	{
		needs[i] = needs[i] - special[i];
	}
}

void undoOffer(vector<int> special, vector<int>& needs)
{
	for (int i = 0; i < needs.size(); i++)
	{
		needs[i] = special[i] + needs[i];
	}
}

// Bruteforce Solution
int shoppingOffersHelper(vector<int> price, vector<vector<int>> special, vector<int>& needs)
{
	if (checkNeeds(needs))
		return 0;

	// Apply original price
	int totalPrice = 0;
	for (int i = 0; i < price.size(); i++)
	{
		totalPrice += needs[i] * price[i];
	}

	// Apply each offer
	for (int i = 0; i < special.size(); i++)
	{
		if (checkNeedsFitOffers(special[i], needs))
		{
			consumeOffer(special[i], needs);
			int withOffer = special[i].back() + shoppingOffersHelper(price, special, needs);
			totalPrice = min(totalPrice, withOffer);
			undoOffer(special[i], needs);
		}
	}

	return totalPrice;
}

// Memoization Solution
int shoppingOffersHelper(vector<int> price, vector<vector<int>> special, vector<int>& needs, map<vector<int>, int>& dp)
{
	if (checkNeeds(needs))
		return 0;

	if (dp.find(needs) != dp.end())
		return dp[needs];

	// Apply original price
	int totalPrice = 0;
	for (int i = 0; i < price.size(); i++)
	{
		totalPrice += needs[i] * price[i];
	}

	// Apply each offer
	for (int i = 0; i < special.size(); i++)
	{
		if (checkNeedsFitOffers(special[i], needs))
		{
			consumeOffer(special[i], needs);
			int withOffer = special[i].back() + shoppingOffersHelper(price, special, needs, dp);
			totalPrice = min(totalPrice, withOffer);
			undoOffer(special[i], needs);
		}
	}

	return dp[needs] = totalPrice;
}

int shoppingOffers(vector<int> price, vector<vector<int>> special, vector<int> needs)
{
	map<vector<int>, int> dp;

	return shoppingOffersHelper(price, special, needs, dp);
}

int main()
{
	cout << shoppingOffers({ 2, 5 }, { {3, 0, 5}, {1, 2, 10} }, { 3, 2 }) << endl; // 14$

	cout << shoppingOffers({ 2, 3, 4 }, { {1, 1, 0, 4}, {2, 2, 1, 9} }, { 1, 2, 1 }) << endl; // 11$

	return 0;
}