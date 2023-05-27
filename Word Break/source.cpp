#include<iostream>
#include<vector>
using namespace std;

/*
	Problem Number: #139
	Problem Difficulty: Medium
*/

/*
	Bruteforce Approach
	n = s.size()
	m = wordDict.size()

	Time Complexity: O(2^n * n) [for every recursive call, we perform substr() operation on the main string, and this operation takes O(n)]
	Space Complexity: O(n)
*/
bool wordBreakHelper(int index, string s, vector<string> wordDict) {
	if (index >= s.size()) {
		return true;
	}

	for (int i = 0; i < wordDict.size(); i++) {
		int wordDictSize = wordDict[i].size();
		int scope = index + wordDictSize - 1;
		string subStr = s.substr(index, wordDictSize);
		if (subStr == wordDict[i]) {
			if (wordBreakHelper(scope + 1, s, wordDict)) {
				return true;
			}
		}
	}

	return false;
}

/*
	Memoization Solution
	n = s.size()
	m = wordDict.size()

	Time Complexity: O(n*m)
	Space Complexity: O(n)
*/
bool wordBreakHelper(int index, string s, vector<string> wordDict, vector<int>& dp) {
	if (index >= s.size()) {
		return true;
	}

	if (dp[index] != -1) {
		return dp[index];
	}

	for (int i = 0; i < wordDict.size(); i++) {
		int wordDictSize = wordDict[i].size();
		int scope = index + wordDictSize;
		string subStr = s.substr(index, wordDictSize);
		if (subStr == wordDict[i]) {
			if (wordBreakHelper(scope, s, wordDict, dp)) {
				return dp[index] = true;
			}
		}
	}

	return dp[index] = false;
}

bool wordBreak(string s, vector<string> wordDict) {
	vector<int> dp(s.size() + 1, -1);

	return wordBreakHelper(0, s, wordDict, dp);
}

int main()
{
	cout << wordBreak("abcd", { "a", "abc", "b", "cd"}) << endl; // true | 1
	cout << wordBreak("leetcode", {"leet", "code"}) << endl; // true | 1
	cout << wordBreak("applepenapple", {"apple", "pen"}) << endl; // true | 1
	cout << wordBreak("thebrokenmachine", {"the", "machine", "broken"}) << endl; // true | 1
	cout << wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << endl; // false | 0

	return 0;
}