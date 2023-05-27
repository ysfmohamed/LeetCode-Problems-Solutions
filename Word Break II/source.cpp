#include<iostream>
#include<vector>
using namespace std;

/*
	Problem Number: #140
	Problem Difficulty: Hard
*/


/*
	Bruteforce Approach
	Time Complexity: O(2^n * n)
	Space Compelxity: O(n)
*/
void wordBreakHelper(int index, string s, vector<string> wordDict, vector<string>& sentences , string currChoice) {
	if (index >= s.size()) {
		sentences.push_back(currChoice);
		return;
	}

	for (int i = 0; i < wordDict.size(); i++) {
		int wordDictSize = wordDict[i].size();
		int scope = index + wordDictSize;
		string subStr = s.substr(index, wordDictSize);

		if (subStr == wordDict[i]) {
			if (currChoice != "" && currChoice[currChoice.size() - 1] != ' ') {
				currChoice += " ";
			}
			wordBreakHelper(scope, s, wordDict, sentences, currChoice + wordDict[i]);
		}
	}
}

vector<string> wordBreak(string s, vector<string> wordDict)
{
	vector<string> sentences;

	wordBreakHelper(0, s, wordDict, sentences, "");

	return sentences;
}

void output(vector<string> solution) {
	cout << "[";
	for (int i = 0; i < solution.size(); i++) {
		if (i == solution.size() - 1)
			cout << solution[i];
		else
			cout << solution[i] << ", ";
	}
	cout << "]";
	cout << endl;
}

int main()
{
	vector<string> solution;

	solution = wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"}); // ["cats and dog", "cat sand dog"]
	output(solution);

	solution = wordBreak("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}); // ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
	output(solution);

	solution = wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"});
	output(solution);

	return 0;
}