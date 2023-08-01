#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 684
	Problem Difficulty: Medium
*/

class DisjointSet {
	vector<int> parents, weights;

public:
	DisjointSet(int n) {
		weights.resize(n + 1, 1);
		parents.resize(n + 1);

		for (int i = 0;  i <= n; i++) {
			parents[i] = i;
		}
	}

	int findParent(int node) {
		if (node == parents[node])
			return node;

		return parents[node] = findParent(parents[node]);
	}

	void unionSet(int u, int v) {
		int parentU = findParent(u);
		int parentV = findParent(v);

		if (parentU == parentV) return;

		if (weights[parentU] < weights[parentV]) {
			parents[parentU] = parentV;
			weights[parentV] += weights[parentU];
		}
		else {
			parents[parentV] = parentU;
			weights[parentU] += weights[parentV];
		}
	}

	vector<int> getParents() {
		return parents;
	}
};

/*
	Disjoint Set solution
	Time Complexity: O(V)
	Space Complexity: O(V)
*/
vector<int> findRedundantConnection2(vector<vector<int>> edges) {
	int n = edges.size();

	DisjointSet ds(n);

	pair<int, int> redundantEdge;

	for (int i = 0 ; i < n; i++) {
		if (ds.findParent(edges[i][0]) == ds.findParent(edges[i][1])) {
			redundantEdge = make_pair(edges[i][0], edges[i][1]);
		}
		ds.unionSet(edges[i][0], edges[i][1]);
	}

	return {redundantEdge.first, redundantEdge.second};
}


void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], pair<int, int>& candidateEdge) {
	visited[node] = 1;

	for (auto neighbourNode : adj[node]) {
		if (visited[neighbourNode] == 0) {
			dfs(neighbourNode, node, visited, adj, candidateEdge);
		}
		else if (parent != neighbourNode) {
			candidateEdge = make_pair(node, neighbourNode);
		}
	}
}
/*
	DFS Solution
	Time Complexity: O(V*(V+2E)) + O(Elog(E))
	Space Complexity: O(V+2E) + O(V)
*/
vector<int> findRedundantConnection(vector<vector<int>> edges) {
	int n = edges.size();
	int maxNode = -1;

	for (int i = 0; i < n; i++) {
		maxNode = max(maxNode, max(edges[i][0], edges[i][1]));
	}

	vector<int> adj[maxNode];

	for (int i = 0; i < n; i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	pair<int, int> candidateEdge;
	set<pair<int, int>> candidateEdges;

	for (int i = 0; i < n; i++) {
		vector<int> visited(maxNode + 1, 0);

		dfs(i, -1, visited, adj, candidateEdge);
		candidateEdges.insert(candidateEdge);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (candidateEdges.find({edges[i][0], edges[i][1]}) != candidateEdges.end()) {
			return {edges[i][0], edges[i][1]};
		}
	}

	return {candidateEdge.first, candidateEdge.second}; // unreachable
}

int main() {

	return 0;
}