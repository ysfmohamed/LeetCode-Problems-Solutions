#include<iostream>
#include<vector>
using namespace std;

/*
* Bruteforce Solution
* Time Complexity: O(n * n * n) = O(n^3)
* Space Complexity: O(n^2)
*/
int orderOfLargestPlusSign(int n, vector<vector<int>> mines)
{
    vector<vector<int>> grid(n, vector<int>(n, 1));

    for (int i = 0; i < mines.size(); i++)
    {
        grid[mines[i][0]][mines[i][1]] = 0;
    }

    int maxSize = 0, minArm = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int upArm = 0, rightArm = 0, downArm = 0, leftArm = 0;
            int up = i - 1;
            while (up >= 0 && up < n && grid[up][j] != 0) {
                upArm++;
                up--;
            }

            int right = j + 1;
            while (right >= 0 && right < n && grid[i][right] != 0) {
                rightArm++;
                right++;
            }

            int down = i + 1;
            while (down >= 0 && down < n && grid[down][j] != 0) {
                downArm++;
                down++;
            }

            int left = j - 1;
            while (left >= 0 && left < n && grid[i][left] != 0) {
                leftArm++;
                left--;
            }

            if (grid[i][j] == 1)
                minArm = min(upArm, min(rightArm, min(downArm, leftArm))) + 1;
            else
                minArm = min(upArm, min(rightArm, min(downArm, leftArm)));

            maxSize = max(maxSize, minArm);
        }
    }

    return maxSize;
}

/*
* Optimized Solution
* Time Complexity: O(4 * n^2) = O(n^2)
* Space Complexity: O(4 * n^2) = O(n^2)
*/

int orderOfLargestPlusSign2(int n, vector<vector<int>> mines)
{
    vector<vector<int>> grid(n, vector<int>(n, 1));
    for (int i = 0; i < mines.size(); i++)
    {
        grid[mines[i][0]][mines[i][1]] = 0;
    }

    vector<vector<int>> up = grid, right = grid, down = grid, left = grid;

    // fill up table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (up[i][j] == 1)
            {
                up[i][j] += up[i - 1][j];
            }
        }
    }

    // fill right table
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (right[i][j] == 1)
            {
                right[i][j] += right[i][j + 1];
            }
        }
    }

    // fill down table
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (down[i][j] == 1)
            {
                down[i][j] += down[i + 1][j];
            }
        }
    }

    // fill left table
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (left[i][j] == 1)
            {
                left[i][j] += left[i][j - 1];
            }
        }
    }

    int maxPlusSize = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxPlusSize = max(maxPlusSize, min(up[i][j], min(right[i][j], min(down[i][j], left[i][j]))));
        }
    }

    return maxPlusSize;
}

int main()
{
	cout << orderOfLargestPlusSign2(5, { {4, 2} }) << endl; // 2
	cout << orderOfLargestPlusSign2(1, { {0, 0} }) << endl; // 0
	cout << orderOfLargestPlusSign2(2, { {0, 0}, {0, 1}, {1, 0} }) << endl; // 1

	return 0;
}