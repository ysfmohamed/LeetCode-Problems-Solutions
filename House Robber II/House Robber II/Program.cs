// Problem number: #213
// Difficulty: Medium

int rob(int[] nums)
{
    /*
     * Time Complexity: O(n)
     * Space Complexity: O(2n) => O(n)
     */
    int[] dp_1 = new int[nums.Length];
    int[] dp_2 = new int[nums.Length];

    if (nums.Length == 1) return nums[0];
    else if (nums.Length == 2) return Math.Max(nums[0], nums[1]);

    dp_1[1] = nums[0];
    dp_1[2] = Math.Max(nums[0], nums[1]);
    for (int i = 3; i <= dp_1.Length - 1; i++)
    {
        dp_1[i] = Math.Max(nums[i - 1] + dp_1[i - 2], dp_1[i - 1]);
    }

    dp_2[nums.Length - 1] = nums[nums.Length - 1];
    dp_2[nums.Length - 2] = Math.Max(nums[nums.Length - 1], nums[nums.Length - 2]);
    for (int i = nums.Length - 3; i > 0; i--)
    {
        dp_2[i] = Math.Max(nums[i] + dp_2[i + 2], dp_2[i + 1]);
    }

    return Math.Max(dp_1[nums.Length - 1], dp_2[1]);
}
