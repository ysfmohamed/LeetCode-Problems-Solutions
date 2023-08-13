#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 1129
	Problem Difficulty: Medium
*/

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> redEdges, vector<vector<int>> blueEdges) {
	// THE WORST GRAPH REPRESENTION EVER!

	unordered_map<int, unordered_map<int, vector<char>>> adj;
	for (auto rEdge : redEdges) {
		adj[rEdge[0]].insert({rEdge[1], {'r'}});
	}

	for (auto bEdge : blueEdges) {
		auto foundBEdge = adj[bEdge[0]];
		if (foundBEdge.find(bEdge[1]) != foundBEdge.end()) {
			adj[bEdge[0]][bEdge[1]].push_back('b');
		} else {
			adj[bEdge[0]].insert({bEdge[1], {'b'}});
		}
	}

	vector<int> dist(n, INT_MAX);
	dist[0] = 0;

	queue<pair<pair<int, int>, char>> queue;
	queue.push({{0, 0}, ' '});

	set<pair<int, char>> visited;
	visited.insert({0, ' '});

	while (!queue.empty()) {
		int currNode = queue.front().first.first;
		int currDist = queue.front().first.second;
		char currColor = queue.front().second;
		queue.pop();

		dist[currNode] = min(dist[currNode], currDist);

		for (auto map : adj[currNode]) {
			int nodeToBeReached = map.first;
			vector<char> colors = map.second;
			for (auto color : colors) {
				if (color != currColor && visited.find({nodeToBeReached, color}) == visited.end()) {
					visited.insert({nodeToBeReached, color});
					queue.push({{nodeToBeReached, currDist + 1}, color});
				}
			}
		}
	}

	replace(dist.begin(), dist.end(), INT_MAX, -1);

	return dist;
}

void output(vector<int> solution) {
	for (auto num : solution) {
		cout << num << " ";
	}

	cout << endl;
	cout << "############################" << endl;
}

int main() {
	vector<int> solution;

	solution = shortestAlternatingPaths(5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {2, 5}}, {{1, 2}, {2, 3}, {3, 1}});
	output(solution);

	return 0;
}