#include<iostream>
#include<vector>
using namespace std;

/*
* Problem Number: #97
* Problem Difficulty: Medium
*/


/*
* Bruteforce Solution
* n = s1.size()
* m = s2.size()
* k = s3.size()
* Time Complexity: O(2^k)
* Space Complexity: O(k)
*/
bool isInterleaveHelper(int i, int j, int k, string s1, string s2, string s3)
{
	if (i == s1.size() && j == s2.size())
	{
		return true;
	}

	if (s1[i] == s3[k] && s2[j] != s3[k])
	{
		return isInterleaveHelper(i + 1, j, k + 1, s1, s2, s3);
	}
	else if (s2[j] == s3[k] && s1[i] != s3[k])
	{
		return  isInterleaveHelper(i, j + 1, k + 1, s1, s2, s3);
	}
	else if(s1[i] == s3[k] && s2[j] == s3[k])
	{
		return isInterleaveHelper(i + 1, j, k + 1, s1, s2, s3) || isInterleaveHelper(i, j + 1, k + 1, s1, s2, s3);
	}

	else
		return false;
}

/*
* Memoized Solution
* n = s1.size()
* m = s2.size()
* k = s3.size()
* Time Complexity: O(nm)
* Soace Complexity: O(nm) + O(k)
*/
bool isInterleaveHelper(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& dp)
{
	if (i == s1.size() && j == s2.size())
	{
		return true;
	}

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s3[k] && s2[j] != s3[k])
	{
		return dp[i][j] = isInterleaveHelper(i + 1, j, k + 1, s1, s2, s3, dp);
	}
	else if (s2[j] == s3[k] && s1[i] != s3[k])
	{
		return  dp[i][j] = isInterleaveHelper(i, j + 1, k + 1, s1, s2, s3, dp);
	}
	else if (s1[i] == s3[k] && s2[j] == s3[k])
	{
		return dp[i][j] = isInterleaveHelper(i + 1, j, k + 1, s1, s2, s3, dp) || isInterleaveHelper(i, j + 1, k + 1, s1, s2, s3, dp);
	}

	else
		return dp[i][j] = false;
}

bool isInterleave(string s1, string s2, string s3)
{
	if (s1.size() + s2.size() != s3.size())
		return false;

	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

	return isInterleaveHelper(0, 0, 0, s1, s2, s3, dp);
}

int main()
{
	cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl; // true
	cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl; // false

	return 0;
}