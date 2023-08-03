#include<bits/stdc++.h>
using namespace std;

/*
	Bruteforce solution
	Time Complexity: O(2^n)
	Spae Complexity: O(n)
*/
int minimumTotalHelper(int i, int j, vector<vector<int>>& triangle) {
	if (i == triangle.size() || j == triangle.size()) {
		return 0;
	}

	return triangle[i][j] + min(minimumTotalHelper(i + 1, j, triangle), minimumTotalHelper(i + 1, j + 1, triangle));
}

/*
	Memoization solution
	Time Complexity: O(n^2)
	Space Complexity: O(n^2)
*/
int minimumTotalHelper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
	if (i == triangle.size() || j == triangle.size()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	return dp[i][j] = triangle[i][j] + min(minimumTotalHelper(i + 1, j, triangle, dp), minimumTotalHelper(i + 1, j + 1, triangle, dp));
}

int minimumTotal(vector<vector<int>> triangle) {
	int n = triangle.size();

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

	return minimumTotalHelper(0, 0, triangle, dp);
}

int main() {
	cout << minimumTotal({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}) << endl; // 11

	return 0;
}