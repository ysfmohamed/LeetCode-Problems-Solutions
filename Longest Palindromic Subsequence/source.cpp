#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s) {
	for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}

	return true;
}

/*
	Bruteforce solution
	Time Complexity: O(N * 2^N)
	Space Complexity: O(N)

int longestPalindromeHelper(int i, string currStr, string s) {
	if (i >= s.size()) {
		return 0;
	}

	int take = longestPalindromeHelper(i + 1, currStr + s[i], s);
	int dontTake = longestPalindromeHelper(i + 1, currStr, s);

	string takeStr = currStr + s[i];
	string dontTakeStr = currStr;

	int takeLen = 0;
	int dontTakeLen = 0;

	if (checkPalindrome(takeStr)) {
		int s = takeStr.size();
		takeLen = max(s, max(take, dontTake));
	}

	if (checkPalindrome(dontTakeStr)) {
		int s = dontTakeStr.size();
		dontTakeLen = max(s, max(take, dontTake));
	}

	return max(max(take, dontTake), max(takeLen, dontTakeLen));
}

*/

/*
	Memoization solution

int longestPalindromeHelper(int i, string currStr, string s, map<pair<int, string>, int>& dp) {
	if (i >= s.size()) {
		return 0;
	}

	if (dp.find({i, currStr}) != dp.end()) {
		return dp[ {i, currStr}];
	}

	int take = longestPalindromeHelper(i + 1, currStr + s[i], s, dp);
	int dontTake = longestPalindromeHelper(i + 1, currStr, s, dp);

	string takeStr = currStr + s[i];
	string dontTakeStr = currStr;

	int takeLen = 0;
	int dontTakeLen = 0;

	if (checkPalindrome(takeStr)) {
		int s = takeStr.size();
		takeLen = max(s, max(take, dontTake));
	}

	if (checkPalindrome(dontTakeStr)) {
		int s = dontTakeStr.size();
		dontTakeLen = max(s, max(take, dontTake));
	}

	return dp[ {i, currStr}] = max(max(take, dontTake), max(takeLen, dontTakeLen));
}

*/

/*
	Bruteorce solution
	Time Complexity: O(N) + O(2^(2N))
	Space Complexity: O(2N)
*/
int longestPalindromeHelper(int i, int j, string s1, string s2) {
	if (i >= s1.size() || j >= s2.size()) {
		return 0;
	}

	int skipBoth = 0;
	int skipFirstStr = 0;
	int skipSecondStr = 0;

	if (s1[i] == s2[j]) {
		skipBoth = longestPalindromeHelper(i + 1, j + 1, s1, s2) + 1;
	}

	else {
		skipFirstStr = longestPalindromeHelper(i + 1, j, s1, s2);
		skipSecondStr = longestPalindromeHelper(i, j + 1, s1, s2);
	}

	return max(skipBoth, max(skipFirstStr, skipSecondStr));
}

/*
	Memoization solution
	Time Complexity: O(N) + O(N^2)
	Space Complexity: O(N^2) + O(2N)
*/
int longestPalindromeHelper(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
	if (i >= s1.size() || j >= s2.size()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int skipBoth = 0;
	int skipFirstStr = 0;
	int skipSecondStr = 0;

	if (s1[i] == s2[j]) {
		skipBoth = longestPalindromeHelper(i + 1, j + 1, s1, s2, dp) + 1;
	}

	else {
		skipFirstStr = longestPalindromeHelper(i + 1, j, s1, s2, dp);
		skipSecondStr = longestPalindromeHelper(i, j + 1, s1, s2, dp);
	}

	return dp[i][j] = max(skipBoth, max(skipFirstStr, skipSecondStr));
}

/*
	Tabulation solution
	Time Complexity: O(N) + O(N^2)
	Space Complexity: O(N^2)
*/
int longestPalindromeTab(string s) {
	vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));

	string originalStr = s;
	reverse(s.begin(), s.end());

	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp.size(); j++) {
			if (originalStr[i - 1] == s[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[s.size()][s.size()];
}

int longestPalindromeSubseq(string s) {
	// map<pair<int, string>, int> dp;

	// string originalStr = s;
	// reverse(s.begin(), s.end());

	// vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));

	// return longestPalindromeHelper(0, 0, originalStr, s, dp);

	return longestPalindromeTab(s);
}

int main() {
	cout << longestPalindromeSubseq("bbbab") << endl; // 4

	cout << longestPalindromeSubseq("cbbd") << endl; // 2

	cout << longestPalindromeSubseq("rgerisbaba") << endl; // 3

	cout << longestPalindromeSubseq("t") << endl; // 1

	cout << longestPalindromeSubseq("woeitueywoiw") << endl; // 7

	cout << longestPalindromeSubseq("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew") << endl; // 159

	cout << longestPalindromeSubseq("owihgiuoshoejfeoijfsfsrgsirouhgnulfdkbjxfnbwgdgfjygeriogjmwerwaosmvfldkvpoefjosijgsuerhgnisuegreewuihfufhdsjbfsgd") << endl; // 43

	return 0;
}