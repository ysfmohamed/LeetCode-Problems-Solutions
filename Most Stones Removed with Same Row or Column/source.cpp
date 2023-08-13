#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 947
	Problem Difficulty: Medium
*/

class DisjointSet {
	vector<int> parents, weights;

public:
	DisjointSet(int n) {
		weights.resize(n + 1, 1);
		parents.resize(n + 1);

		for (int i = 0 ; i <= n; i++) {
			parents[i] = i;
		}
	}

	int findParent(int node) {
		if (node == parents[node])
			return node;

		return parents[node] = findParent(parents[node]);
	}

	void unionBySet(int u, int v) {
		int parentU = findParent(u);
		int parentV = findParent(v);

		if (parentU == parentV)
			return;

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

int removeStones(vector<vector<int>>& stones) {
	int cols = 0;
	int rows = 0;

	for (auto stone : stones) {
		rows = max(rows, stone[0]);
		cols = max(cols, stone[1]);
	}

	DisjointSet ds(rows + cols + 2);
	unordered_set<int> set;
	for (auto stone : stones) {
		int u = stone[0];
		int v = rows + stone[1] + 1;
		ds.unionBySet(u, v);
		set.insert(u);
		set.insert(v);
	}

	int numComponents = 0;
	for (auto node : set) {
		if (ds.findParent(node) == node) {
			numComponents++;
		}
	}

	return stones.size() - numComponents;
}

int main() {

	return 0;
}