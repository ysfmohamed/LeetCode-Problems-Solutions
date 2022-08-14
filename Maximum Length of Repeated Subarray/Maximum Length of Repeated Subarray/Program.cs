/*
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 */
int findLength(int[] nums1, int[] nums2)
{
    int[,] dp = new int[nums1.Length + 1, nums2.Length + 1];
    int maxValue = 0;

    for (int i = 1; i < dp.GetLength(0); i++)
    {
        for (int j = 1; j < dp.GetLength(1); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i, j] = dp[i - 1, j - 1] + 1;
            }
            maxValue = Math.Max(dp[i, j], maxValue);
        }
    }

    return maxValue;
}