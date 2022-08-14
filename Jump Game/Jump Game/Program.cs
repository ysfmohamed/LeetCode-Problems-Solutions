/*
 * Problem number: 55
 * Difficulty: Medium
 * 
 * Time Complexity: O(n^m)
 * Space Complexity: O(n)
 */
bool CanJump(int[] nums)
{
    Dictionary<int, bool> dic = new Dictionary<int, bool>();
    return canJumpHelper(0, nums, dic);
}

bool canJumpHelper(int index, int[] nums, Dictionary<int, bool> dic)
{
    if (dic.ContainsKey(index))
        return dic[index];

    if (index >= nums.Length)
        return dic[index] = false;

    if (index == nums.Length - 1)
        return dic[index] = true;

    if (index != nums.Length - 1 && nums[index] == 0)
        return dic[index] = false;

    for (int i = 1; i <= nums[index]; i++)
    {
        if (canJumpHelper(index + i, nums, dic))
            return dic[index] = true;
    }

    return dic[index] = false;
}

/*bool canJumpHelper(int index, int[] nums)
{
    if (index >= nums.Length)
        return false;

    if (index == nums.Length - 1)
        return true;

    if (index != nums.Length - 1 && nums[index] == 0)
        return false;

    for (int i = 1; i <= nums[index]; i++)
    {
        if (canJumpHelper(index + i, nums))
            return true;
    }

    return false;
}*/