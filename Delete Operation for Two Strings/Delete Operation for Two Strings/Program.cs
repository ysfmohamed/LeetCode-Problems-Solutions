// Problem number: #583
// Difficulty: Medium

int minDistance(string word1, string word2)
{
    /*
     * Time Complexity: O(n*m)
     * Space Complexity: O(n*m)
     */
    
    int[,] table = new int[word1.Length + 1, word2.Length + 1];

    //Seeding values are EXTREMELY IMPORTANT
    for (int i = 1; i < table.GetLength(0); i++)
    {
        table[i, 0] = i;
    }

    for (int i = 1; i < table.GetLength(1); i++)
    {
        table[0, i] = i;
    }

    for (int i = 1; i < table.GetLength(0); i++)
    {
        for (int j = 1; j < table.GetLength(1); j++)
        {
            if (word1[i - 1] == word2[j - 1])
                table[i, j] = table[i - 1, j - 1];

            else
                table[i, j] = 1 + Math.Min(table[i - 1, j], table[i, j - 1]);
        }
    }

    return table[word1.Length, word2.Length];

    /*int[,] memo = new int[word1.Length, word2.Length];

    for (int i = 0; i < memo.GetLength(0); i++)
    {
        for (int j = 0; j < memo.GetLength(1); j++)
        {
            memo[i, j] = -1;
        }
    }*/

    //return minDistanceHelper(word1, word2, word1.Length - 1, word2.Length - 1, memo);
    //return minDistanceHelper(word1, word2, word1.Length - 1, word2.Length - 1);
}

/*
 * Bruteforce solution
 * Space Complexity: O(2^(n+m))
 */
int minDistanceHelper(string word1, string word2, int w1Index, int w2Index)
{
    if (w1Index < 0)
        return w2Index + 1;

    if (w2Index < 0)
        return w1Index + 1;

    if (word1[w1Index] == word2[w2Index])
        return minDistanceHelper(word1, word2, w1Index - 1, w2Index - 1);

    else
        return 1 + Math.Min(minDistanceHelper(word1, word2, w1Index - 1, w2Index), minDistanceHelper(word1, word2, w1Index, w2Index - 1));
}

/*
 * Memoization solution
 * Time Complexity: O(n*m)
 */
/*int minDistanceHelper(string word1, string word2, int w1Index, int w2Index, int[,] memo)
{
    if (w1Index < 0)
        return w2Index + 1;

    if (w2Index < 0)
        return w1Index + 1;

    if (memo[w1Index, w2Index] != -1)
        return memo[w1Index, w2Index];

    if (word1[w1Index] == word2[w2Index])
        return memo[w1Index, w2Index] = minDistanceHelper(word1, word2, w1Index - 1, w2Index - 1, memo);

    else
    {
        return memo[w1Index, w2Index] = 1 + Math.Min(minDistanceHelper(word1, word2, w1Index - 1, w2Index, memo), minDistanceHelper(word1, word2, w1Index, w2Index - 1, memo));
    }
}*/