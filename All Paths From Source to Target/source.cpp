#include<bits/stdc++.h>
using namespace std;

// BFS solution
vector<vector<int>> allPathsSourceTarget2(vector<vector<int>> graph) {
	int n = graph.size();

	vector<vector<int>> allPaths;
	queue<pair<int, vector<int>>> queue;
	queue.push({0, {0}});

	while (!queue.empty()) {
		int currNode = queue.front().first;
		vector<int> currPath = queue.front().second;
		queue.pop();

		if (currNode == n - 1) {
			allPaths.push_back(currPath);
		}

		for (auto neighbourNode : graph[currNode]) {
			currPath.push_back(neighbourNode);
			queue.push({neighbourNode, currPath});
			currPath.pop_back();
		}
	}

	return allPaths;
}

void dfs(int node, vector<vector<int>>& graph, vector<int>& singlePath, vector<vector<int>>& allPaths) {
	singlePath.push_back(node);

	if (node == graph.size() - 1) {
		allPaths.push_back(singlePath);
		return;
	}

	for (auto neighbourNode : graph[node]) {
		dfs(neighbourNode, graph, singlePath, allPaths);
		singlePath.pop_back();

	}
}

// DFS solution
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
	int n = graph.size();

	vector<int> singlePath;
	vector<vector<int>> allPaths;

	dfs(0, graph, singlePath, allPaths);

	return allPaths;
}

int main() {

	return 0;
}