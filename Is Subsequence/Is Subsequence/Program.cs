/*
 * Problem number: 392
 * Difficulty: Easy
 */

bool isSubsequence(string s, string t)
{
	int firstStringSize = s.Length, secondStringSize = t.Length;

	if (firstStringSize == 0 && secondStringSize == 0) return true;
	else if (firstStringSize == 0 && secondStringSize != 0) return true;
	else if (firstStringSize != 0 && secondStringSize == 0) return false;

	bool[,] table = new bool[s.Length + 1, t.Length + 1];

	for (int j = 1; j <= secondStringSize; j++)
	{
		if (s[0] == t[j - 1])
			table[1,j] = true;
		else
			table[1,j] = table[1,j - 1];
	}

	for (int i = 2; i <= firstStringSize; i++)
	{
		for (int j = i; j <= secondStringSize; j++)
		{

			if (s[i - 1] == t[j - 1] && table[i - 1,j - 1])
				table[i,j] = true;
			else
				table[i,j] = table[i,j - 1];
		}
	}

	return table[firstStringSize,secondStringSize];    
}