/*
 * Problem number: 5
 * Difficulty: Medium
 */

string longestPalindrome(string s)
{
    /*
     * Bruteforce solution (using LCS Longest Common Subsequence)
     * Time Complexity: O(2^n)
     * Space Complexity: O(n)
     */
    int startIndex = 0, endIndex = s.Length - 1;
    int longestPalindromicSubStr = 1;
    int beginningOfCut = 0;
    longestPalindromeHelper(startIndex, endIndex, s, ref longestPalindromicSubStr, ref beginningOfCut);

    return s.Substring(beginningOfCut, longestPalindromicSubStr);
}

bool longestPalindromeHelper(int startIndex, int endIndex, string s, ref int longestPalindromicSubStr, ref int beginningOfCut)
{
    bool foundPalindromicSubStr = false;

    if (startIndex >= endIndex)
        return true;

    if(s[startIndex] == s[endIndex] && longestPalindromeHelper(startIndex + 1, endIndex - 1, s, ref longestPalindromicSubStr, ref beginningOfCut))
    {
        foundPalindromicSubStr = true;

        if (endIndex - startIndex + 1 > longestPalindromicSubStr)
        {
            longestPalindromicSubStr = endIndex - startIndex + 1;
            beginningOfCut = startIndex;
        }
    }

    else
    {
        longestPalindromeHelper(startIndex, endIndex - 1, s, ref longestPalindromicSubStr, ref beginningOfCut);
        longestPalindromeHelper(startIndex + 1, endIndex, s, ref longestPalindromicSubStr, ref beginningOfCut);
    }

    return foundPalindromicSubStr;
}