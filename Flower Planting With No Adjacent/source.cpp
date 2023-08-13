#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 1042
	Problem Difficulty: Medium
*/

vector<int> gardenNoAdj(int n, vector<vector<int>> paths) {
	vector<int> adj[n];

	for (auto path : paths) {
		adj[path[0] - 1].push_back(path[1] - 1);
		adj[path[1] - 1].push_back(path[0] - 1);
	}

	vector<int> res(n);

	for (int i = 0; i < n; i++) {
		int availableFlowers[5] = {};
		for (auto neighbourNode : adj[i]) {
			availableFlowers[res[neighbourNode]] = 1;
		}

		for (int flower = 4; flower > 0; flower--) {
			if (availableFlowers[flower] == 0) {
				res[i] = flower;
			}
		}
	}

	return res;
}

void output(vector<int> solution) {
	for (auto num : solution) {
		cout << num << " ";
	}

	cout << endl;
	cout << "#####################" << endl;
}

int main() {
	vector<int> solution;

	solution = gardenNoAdj(3, {{1, 2}, {2, 3}, {3, 1}});
	output(solution);

	solution = gardenNoAdj(4, {{1, 2}, {3, 4}});
	output(solution);

	solution = gardenNoAdj(4, {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}});
	output(solution);

	solution = gardenNoAdj(5, {{3, 4}, {4, 5}, {3, 2}, {5, 1}, {1, 3}, {4, 2}});
	output(solution);

	return 0;
}