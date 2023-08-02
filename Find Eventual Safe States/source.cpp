#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 802
	Problem Difficulty: Medium
*/

bool isCycle(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& graph) {
	visited[node] = 1;
	pathVisited[node] = 1;

	for (auto neighbourNode : graph[node]) {
		if (visited[neighbourNode] == 0) {
			if (isCycle(neighbourNode, visited, pathVisited, graph) == true) {
				return false;
			}
		}
		else if (visited[neighbourNode] == 1 && pathVisited[neighbourNode] == 1) {
			return true;
		}
	}

	return false;
}

/*
	DFS (detect cycle in directed graph technique) solution
	Time Complexity: O(V(V + E))
*/
vector<int> eventualSafeNodes2(vector<vector<int>> graph) {
	int n = graph.size();

	vector<int> safeNodes;

	for (int i = 0; i < n; i++) {
		vector<int> visited(n, 0);
		vector<int> pathVisited(n, 0);

		if (visited[i] == 0) {
			if (isCycle(i, visited, pathVisited, graph) == false) {
				safeNodes.push_back(i);
			}
		}
	}

	return safeNodes;
}

/*
	Topological Sort solution
	Time Complexity: O(V + E)
*/
vector<int> eventualSafeNodes(vector<vector<int>> graph) {
	int n = graph.size();

	vector<int> invAdj[n];
	for (int i = 0; i < n; i++) {
		for (auto node : graph[i]) {
			invAdj[node].push_back(i);
		}
	}

	vector<int> indegrees(n, 0);
	for (int i = 0; i < n; i++) {
		for (auto node : invAdj[i]) {
			indegrees[node]++;
		}
	}

	queue<int> queue;

	for (int i = 0; i < n; i++) {
		if (indegrees[i] == 0) {
			queue.push(i);
		}
	}

	vector<int> safeNodes;

	while (!queue.empty()) {
		int currNode = queue.front();
		queue.pop();

		safeNodes.push_back(currNode);

		for (auto neighbourNode : invAdj[currNode]) {
			indegrees[neighbourNode]--;
			if (indegrees[neighbourNode] == 0) {
				queue.push(neighbourNode);
			}
		}
	}

	sort(safeNodes.begin(), safeNodes.end());

	return safeNodes;
}

int main() {

	return 0;
}