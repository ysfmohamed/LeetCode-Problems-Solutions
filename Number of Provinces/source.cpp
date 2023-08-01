#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 547
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

// DFS Solution
void dfs(int node, vector<int>& visited, vector<vector<int>>& isConnected) {
	visited[node] = 1;

	for (int i = 0; i < isConnected[node].size(); i++) {
		if (visited[i] == 0 && isConnected[node][i] == 1) {
			dfs(i, visited, isConnected);
		}
	}
}

int findCircleNum(vector<vector<int>> isConnected) {
	int n = isConnected.size();

	DisjointSet ds(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < n; j++) {
			if (isConnected[i][j] == 1) {
				ds.unionSet(i, j);
			}
		}
	}

	int provinces = 0;
	for (int i = 0; i < n; i++) {
		if (ds.getParents()[i] == i) {
			provinces++;
		}
	}

	return provinces;
}

int main() {

	return 0;
}