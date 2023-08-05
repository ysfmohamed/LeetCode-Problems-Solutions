#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 354
	Problem Difficulty: Hard
*/


/*
	Another Bruteforce solution depends on take or don't take technique
	Time Complexity: O(Nlog(N)) + O(2^N)
	Space Complexity: O(N)
*/
// int maxEnvelopesHelper(int curr, int prev, vector<pair<int, int>> envelopes) {
// 	if (curr >= envelopes.size()) {
// 		return 0;
// 	}

// 	int take = 0;
// 	int dontTake = 0;

// 	if (prev == -1 || (
// 	            envelopes[prev].first > envelopes[curr].first &&
// 	            envelopes[prev].second > envelopes[curr].second)) {
// 		take = maxEnvelopesHelper(curr + 1, curr, envelopes) + 1;
// 	}

// 	dontTake = maxEnvelopesHelper(curr + 1, prev, envelopes);

// 	return max(take, dontTake);
// }

/*
	Memoization Solution
	Time Complexity: O(NLlog(N)) + O(N^2)
	Space Complexity: O(N)

	NOTE: We can remove sort step and visit all elements in the recursive function starting from zero to the end of the envelopes array,
	so TC becomes O(N^2) only.
*/
int maxEnvelopesHelper(int index, vector<pair<int, int>>& envelopes, vector<int>& dp) {
	if (index >= envelopes.size()) {
		return 0;
	}

	if (dp[index] != -1) {
		return dp[index];
	}

	int currMax = 1;
	for (int i = index + 1; i < envelopes.size(); i++) {
		if (envelopes[index].first > envelopes[i].first && envelopes[index].second > envelopes[i].second) {
			currMax = max(currMax, maxEnvelopesHelper(i, envelopes, dp) + 1);
		}
	}

	return dp[index] = currMax;
}

int maxEnvelopes(vector<vector<int>> envelopes) {
	vector<pair<int, int>> envDims;

	for (int i = 0; i < envelopes.size(); i++) {
		envDims.push_back({envelopes[i][0], envelopes[i][1]});
	}

	sort(envDims.rbegin(), envDims.rend());

	int ret = 1;
	vector<int> dp(envelopes.size() + 1, -1);
	for (int i = 0; i < envDims.size(); i++) {
		ret = max(ret, maxEnvelopesHelper(i, envDims, dp));
	}

	return ret;

	// return maxEnvelopesHelper(0, -1, envDims);
}

int main() {

	cout << maxEnvelopes({ {5, 4}, {6, 4}, {6, 7}, {2, 3} }) << endl; // 3

	cout << maxEnvelopes({{2, 9}, {4, 1}, {9, 8}, {10, 10}, {2, 7}, {10, 4}, {4, 10}, {8, 3}, {2, 2}, {5, 9}, {4, 7}}) << endl; // 4

	cout << maxEnvelopes({{1, 1}, {5, 3}, {6, 9}, {2, 6}, {7, 1}, {5, 3}, {2, 10}, {20, 25}, {19, 18}, {19, 23}, {1, 5}, {5, 3}, {6, 4}}) << endl; // 5

	return 0;
}

// int maxEnvelopesHelper(int curr, int prev, vector<pair<int, int>> envelopes) {
//     if(curr >= envelopes.size()) {
//         return 0;
//     }

//     // if(curr == envelopes.size() - 1) {
//     //     return 0;
//     // }

//     int take = 0;
//     int dontTake = 0;

//     if(prev == -1 || (
//        envelopes[prev].first > envelopes[curr].first &&
//        envelopes[prev].second > envelopes[curr].second)) {
//            take = maxEnvelopesHelper(curr + 1, curr, envelopes) + 1;
//     }

//     dontTake = maxEnvelopesHelper(curr + 1, prev, envelopes);

//     return max(take, dontTake);
// }