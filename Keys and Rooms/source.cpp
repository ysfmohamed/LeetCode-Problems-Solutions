#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 841
	Problem Difficulty: Medium
*/


void dfs(int node, vector<int>& visited, vector<int> adj[]) {
	visited[node] = 1;

	for (auto neighbourNode : adj[node]) {
		if (visited[neighbourNode] == 0) {
			dfs(neighbourNode, visited, adj);
		}
	}
}

/*
	DFS solution
	Time Complexity: O(V + E)
	Space Complexity: O(V + E)
*/
bool canVisitAllRooms(vector<vector<int>> rooms) {
	int n = rooms.size();

	vector<int> adj[n];
	for (int i = 0; i < n; i++) {
		for (auto key : rooms[i]) {
			adj[i].push_back(key);
		}
	}

	vector<int> visited(n, 0);

	dfs(0, visited, adj);

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0)
			return false;
	}

	return true;
}

int main() {

	return 0;
}