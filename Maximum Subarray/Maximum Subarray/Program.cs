Console.WriteLine(maxSubArray(new int[] { -2,-3,-1}));

// Problem number: #53
// Difficulty: Medium

int maxSubArray(int[] nums)
{
    /*
	 * Time Complexity: O(n)
	 * Space Complexity: O(n)
	 */
    int[,] table = new int[2, nums.Length + 1];

    table[0, 0] = table[1, 0] = 0;
    table[0, 1] = table[1, 1] = nums[0];

    for (int i = 2; i <= nums.Length; i++)
    {
        table[1, i] = Math.Max(nums[i - 1], nums[i - 1] + table[1, i - 1]);
        table[0, i] = Math.Max(table[0, i - 1], table[1, i]);
    }

    return table[0, nums.Length];

    /*
	 * Time Complexity: O(n^2)
	 * Space Complexity: O(n)
	 
	int[] table = new int[nums.Length + 1];

	if (nums.Length == 1)
	return nums[0];

	else
	{
		table[1] = nums[0];
		table[2] = Math.Max(nums[0] + nums[1], Math.Max(nums[0], nums[1]));

		int sum = nums[0] + nums[1];
		int helperMax;
		int partialSum;

		for (int i = 3; i <= nums.Length; i++)
		{
			sum += nums[i - 1];
			helperMax = sum;
			partialSum = sum;

			for (int j = 0; j < i - 1; j++)
			{
				partialSum -= nums[j];
				helperMax = Math.Max(helperMax, partialSum);
			}

			table[i] = Math.Max(table[i - 1], helperMax);
		}

		return table[nums.Length];
	}
	*/
}