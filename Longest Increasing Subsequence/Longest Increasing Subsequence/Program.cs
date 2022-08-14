// Problem number: #300
// Difficulty: Medium

int lengthOfLIS(int[] nums)
{
    /*
     * Time Complexity: O(n^2)
     * Space Complexity: O(n)
     */

    if (nums.Length < 2)
        return nums.Length;

    int[] table = new int [nums.Length];

    Array.Fill(table, 1);

    for (int i = 1; i < nums.Length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                table[i] = Math.Max(table[i], table[j] + 1);
        }
    }

    return table.Max();

    /*int res = 1;
    int ret = 0;

    for (int i = 0; i < nums.Length; i++)
    {
        res = Math.Max(res, lengthOfLISHelper(i, nums));
    }

    return res;*/
}

// Bruteforce solution
int lengthOfLISHelper(int position, int[] nums)
{
    int maxValue = 1;
    for (int i = position + 1; i < nums.Length; i++)
    {
        int current = nums[i];
        int prev = nums[position];

        if (current > prev)
        {
            maxValue = Math.Max(maxValue, lengthOfLISHelper(i, nums) + 1);
        }
    }

    return maxValue;
}
