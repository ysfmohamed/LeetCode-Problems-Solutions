#include<iostream>
#include<map>
using namespace std;

/*
* Problem Number: #397
* Problem Difficulty: Medium
*/

long long int intRepHelper(long long int n, map<int, int>& dp)
{
    long long int minOps = LLONG_MAX;
    if (n == 1)
        return 0;

    if (dp.find(n) != dp.end())
        return dp[n];

    if (n % 2 == 0)
    {
        minOps = min(minOps, intRepHelper(n / 2, dp) + 1);
    }

    else
    {
        minOps = min(
            minOps,
            min(intRepHelper(n + 1, dp) + 1, intRepHelper(n - 1, dp) + 1));
    }

    return dp[n] = minOps;
}

int integerReplacement(int n) {
    map<int, int> dp;

    return (int)intRepHelper(n, dp);
}

int main()
{
	cout << integerReplacement(27) << endl;
	cout << integerReplacement(7) << endl;
	cout << integerReplacement(2) << endl;
	cout << integerReplacement(250) << endl;
    cout << integerReplacement(2147483647) << endl;

	return 0;
}