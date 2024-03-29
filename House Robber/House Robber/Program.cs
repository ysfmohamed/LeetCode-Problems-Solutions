﻿// Problem number: #198
// Difficulty: Medium

int rob(int[] nums)
{
    /*
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */

    int[] dp = new int[nums.Length + 1];

    dp[0] = 0;
    dp[1] = nums[0];

    if (nums.Length > 1)
    {
        dp[2] = Math.Max(nums[0], nums[1]);
        for (int i = 3; i < dp.Length; i++)
        {
            dp[i] = Math.Max(dp[i - 2] + nums[i - 1], dp[i - 1]); // Since adjacent houses aren't possible
        }
    }

    return dp[nums.Length];

    // Bruteforce
    /*int maxValue = 0;
    for(int i = 0; i < nums.Length; i++)
    {
        maxValue = Math.Max(maxValue, robHelper(i, nums));
    }

    return maxValue;*/
}

int robHelper(int index, int[] nums)
{
    int maxValue = 0;

    if (index >= nums.Length)
        return 0;

    for(int i = index; i < nums.Length; i++)
    {
        maxValue = Math.Max(maxValue, robHelper(i + 2, nums) + nums[i]);
    }

    return maxValue;
}