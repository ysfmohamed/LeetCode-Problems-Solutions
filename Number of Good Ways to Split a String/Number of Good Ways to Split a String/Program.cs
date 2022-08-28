/*
 * Problem Number: 1525
 * Difficulty: Medium
 */

Console.WriteLine(numSplits("a")); // 0
Console.WriteLine(numSplits("aa")); // 1
Console.WriteLine(numSplits("aacaba")); // 2
Console.WriteLine(numSplits("abcd")); // 1
Console.WriteLine(numSplits("aaregporewgaaasrfokgfsdaadahxjcvajiogjeroisgaaerkrpoekgsaaadwieohfaaa")); // 1

int numSplits(string s)
{
    /*
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    int[] dp_1 = new int[s.Length];
    int[] dp_2 = new int[s.Length];
    HashSet<char> firstHalveSet = new HashSet<char>();
    HashSet<char> secondHalveSet = new HashSet<char>();

    for(int i = 1; i <= dp_1.Length - 1; i++)
    {
        firstHalveSet.Add(s[i-1]);
        dp_1[i] = firstHalveSet.Count;
    }

    for (int i = s.Length - 1, index = 1; i >= 1; i--, index++)
    {
        secondHalveSet.Add(s[i]);
        dp_2[index] = secondHalveSet.Count;
    }

    int countNumSplits = 0;
    int ptrOnDp1 = dp_1.Length - 1, ptrOnDp2 = 1;
    while(ptrOnDp1 != 0 && ptrOnDp2 != dp_2.Length)
    {
        if (dp_1[ptrOnDp1] == dp_2[ptrOnDp2])
            countNumSplits++;

        ptrOnDp1--;
        ptrOnDp2++;
    }

    return countNumSplits;
}

// Time Complexity: O([n - 1] * [n + n + n]) = O(3n^2 - 3n) = O(n^2)
// Space Complexity: O(n)
/*int numSplits(string s)
{
    int countSplits = 0;
    string firstHalve = "", secondHalve = "";
    HashSet<char> firstHalveSet = new HashSet<char>();
    HashSet<char> secondHalveSet = new HashSet<char>();

    for(int i = 0; i < s.Length - 1; i++)
    {
        firstHalve = s[0..(i+1)];
        secondHalve = s[(i + 1)..s.Length];

        for (int j = 0; j < firstHalve.Length; j++)
        {
            firstHalveSet.Add(firstHalve[j]);
        }
        for (int j = 0; j < secondHalve.Length; j++)
        {
            secondHalveSet.Add(secondHalve[j]);
        }

        if (firstHalveSet.Count == secondHalveSet.Count)
            countSplits++;

        firstHalveSet.Clear();
        secondHalveSet.Clear();
    }

    return countSplits;
}*/