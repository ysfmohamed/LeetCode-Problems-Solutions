#include<bits/stdc++.h>
using namespace std;

/*
  Problem Number: 576
  Problem Difficulty: Medium
*/

/*
  Bruteforce solution
*/
int findPathsHelper(int rows, int cols, int numMoves, int maxMove, int sR, int sC) {
  if (numMoves > maxMove) {
    return 0;
  }

  if (sR == -1 && numMoves <= maxMove) {
    return 1;
  }

  if (sR >= rows && numMoves <= maxMove) {
    return 1;
  }

  if (sC == -1 && numMoves <= maxMove) {
    return 1;
  }

  if (sC >= cols && numMoves <= maxMove) {
    return 1;
  }

  int top = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR - 1, sC);
  int right = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR, sC + 1);
  int down = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR + 1, sC);
  int left = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR, sC - 1);

  return top + right + down + left;
}

/*
  Memoization solution
*/
int findPathsHelper(int rows, int cols, int numMoves, int maxMove, int sR, int sC, vector<vector<vector<long long>>>& dp) {
  if (numMoves > maxMove) {
    return 0;
  }

  if (sR == -1 && numMoves <= maxMove) {
    return 1;
  }

  if (sR >= rows && numMoves <= maxMove) {
    return 1;
  }

  if (sC == -1 && numMoves <= maxMove) {
    return 1;
  }

  if (sC >= cols && numMoves <= maxMove) {
    return 1;
  }

  if (dp[sR][sC][numMoves] != -1) {
    return dp[sR][sC][numMoves];
  }

  int top = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR - 1, sC, dp);
  int right = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR, sC + 1, dp);
  int down = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR + 1, sC, dp);
  int left = findPathsHelper(rows, cols, numMoves + 1, maxMove, sR, sC - 1, dp);

  long long mod = 1e9 + 7;

  return dp[sR][sC][numMoves] = ((top % mod) + (right % mod) + (down % mod) + (left % mod)) % mod;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
  vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(maxMove + 1, -1)));

  return findPathsHelper(m, n, 0, maxMove, startRow, startColumn, dp);
}

int main() {
  cout << findPaths(2, 2, 2, 0, 0) << endl; // 6

  cout << findPaths(1, 3, 3, 0, 1) << endl; // 12

  cout << findPaths(10, 10, 8, 5, 7) << endl; // 2685

  cout << findPaths(50, 50, 19, 35, 17) << endl; // 64788

  cout << findPaths(8, 50, 23, 5, 26) << endl; // 914783380

  return 0;
}