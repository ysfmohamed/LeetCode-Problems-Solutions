/*
 * Problem number: 413
 * Difficulty: Medium
 * 
 * Time Complexity: O(n)
 * Spae Complexity: O(n)
 */
int NumberOfArithmeticSlices(int[] nums)
{
    if (nums.Length < 3) return 0;

    int[] table = new int[nums.Length + 1];
    int[] arr = new int[nums.Length - 1];

    for (int i = 0; i < arr.Length; i++)
    {
        arr[i] = nums[i] - nums[i + 1];
    }

    for (int i = 1; i < arr.Length; i++)
    {
        if (arr[i] == arr[i - 1])
            table[i + 2] = table[(i + 2) - 1] + 1;
    }

    int sum = 0;

    foreach (int num in table)
        sum += num;

    return sum;
}
