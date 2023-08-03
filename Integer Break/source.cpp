#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 343
	Problem Difficulty: Medium
*/

/*
	Bruteforce solution
*/
int integerBreakHelper(int n, int target) {
	if (n == target) return 1;
	if (n > target) return 0;

	int maxProd = INT_MIN;
	for (int i = 1; i < target; i++) {
		maxProd = max(maxProd, integerBreakHelper(n + i, target) * i);
	}

	return maxProd;
}

/*
	Memoization solution
*/
int integerBreakHelper(int n, int target, vector<int>& dp) {
	if (n == target) return 1;
	if (n > target) return 0;

	if (dp[n] != -1) {
		return dp[n];
	}

	int maxProd = INT_MIN;
	for (int i = 1; i < target; i++) {
		maxProd = max(maxProd, integerBreakHelper(n + i, target, dp) * i);
	}

	return dp[n] = maxProd;
}

int integerBreak(int n) {
	vector<int> dp(n + 1, -1);

	return integerBreakHelper(0, n, dp);
}

int main() {
	cout << integerBreak(10) << endl; // 36

	return 0;
}