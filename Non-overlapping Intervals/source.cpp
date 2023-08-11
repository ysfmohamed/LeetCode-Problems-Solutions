#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 435
	Problem Difficulty: Medium
*/


/*
	Sorting + Bruteforce solution
	Time Complexity: O(N*log(N)) + O(2^N);
	Space Complexity: O(N)
*/
int eraseHelper(int curr, int prev, vector<pair<int, int>>& intervals) {
	if (curr >= intervals.size()) {
		return 0;
	}

	int take = 0;
	if (prev == -1 || intervals[curr].first >= intervals[prev].second) {
		take = eraseHelper(curr + 1, curr, intervals) + 1;
	}

	int dontTake = eraseHelper(curr + 1, prev, intervals);

	return max(take, dontTake);
}

/*
	Sorting + Memoization solution
	Time Complexity: O(N*log(N)) + O(N^2)
	Space Complexity: O(N) + O(N^2)
*/
int eraseHelper(int curr, int prev, vector<pair<int, int>>& intervals, vector<vector<int>>& dp) {
	if (curr >= intervals.size()) {
		return 0;
	}

	if (dp[curr][prev + 1] != -1) {
		return dp[curr][prev + 1];
	}

	int take = 0;
	if (prev == -1 || intervals[curr].first >= intervals[prev].second) {
		take = eraseHelper(curr + 1, curr, intervals, dp) + 1;
	}

	int dontTake = eraseHelper(curr + 1, prev, intervals, dp);

	return dp[curr][prev + 1] = max(take, dontTake);
}

/*
	Custom sorting solution
	Time Complexity: O(N*log(N)) + O(N)
	Space Complexity: O(N)
*/
int eraseOverlapIntervals2(vector<vector<int>> intervals) {
	int n = intervals.size();

	vector<pair<int, int>> intvs;

	for (auto interval : intervals) {
		intvs.push_back({interval[0], interval[1]});
	}

	auto comparator = [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	};

	sort(intvs.begin(), intvs.end(), comparator);

	stack<pair<int, int>> stack;
	stack.push(intvs[0]);

	for (int i = 1; i < n; i++) {
		pair<int, int> last = stack.top();
		if (last.second <= intvs[i].first) {
			stack.push(intvs[i]);
		}
	}

	return n - stack.size();
}

int eraseOverlapIntervals(vector<vector<int>> intervals) {
	return eraseOverlapIntervals2(intervals);

	// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	// return n - eraseHelper(0, -1, intvs, dp);
}

int main() {

	cout << eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) << endl; // 1
	cout << eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) << endl; // 2
	cout << eraseOverlapIntervals({{1, 2}, {2, 3}}) << endl; // 0
	cout << eraseOverlapIntervals({{1, 10}}) << endl; // 0
	cout << eraseOverlapIntervals({{2, 6}, {4, 8}, {1, 9}, {0, 8}, { -1, 9}, { -10, -7}, {2, 4}, {1, 2}, {1, 10}, {4, 9}, { -2, -1}, {0, 1}, {4, 8}}) << endl; // 7


	return 0;
}