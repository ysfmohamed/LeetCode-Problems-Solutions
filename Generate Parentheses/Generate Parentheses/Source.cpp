#include<iostream>
#include<vector>
using namespace std;

/*
* Problem number: #22
* Problem Difficulty: Medium
*/

/*
* Bruteforce:
* Time Complexity: O(2^(2n))
* Space Complexity: 
*	O(2n) for call stack
*	O(2^(2n)) for 2D vector paranthesis
*/

void generateParanthesisHelper(int i, int j, vector<string>& paranthesis, string str)
{
	// It means that we reached a possible combination.
	if (i == 0 && j == 0)
	{
		paranthesis.push_back(str);
		return;
	}

	// We cannot take a close paran, so we should choose only open paran.
	if (i == j)
	{
		return generateParanthesisHelper(i - 1, j, paranthesis, str + '(');
	}

	if (i > 0)
		generateParanthesisHelper(i - 1, j, paranthesis, str + '(');

	if (j > 0)
		generateParanthesisHelper(i, j - 1, paranthesis, str + ')');
}

vector<string> generateParanthesis(int n)
{
	vector<string> paranthesis;

	generateParanthesisHelper(n-1, n, paranthesis, "(");

	return paranthesis;
}

void outputSolution(vector<string> paranthesis)
{
	cout << "[" << endl;
	for (int i = 0; i < paranthesis.size(); i++)
	{
		cout << "  " << paranthesis[i] << "," << endl;
	}
	cout << "]" << endl;

	cout << "############## END ##############" << endl;
}

int main()
{
	vector<string> paranthesis;

	paranthesis = generateParanthesis(1);
	outputSolution(paranthesis);

	paranthesis = generateParanthesis(3);
	outputSolution(paranthesis);

	paranthesis = generateParanthesis(4);
	outputSolution(paranthesis);

	return 0;
}