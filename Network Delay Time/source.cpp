#include<bits/stdc++.h>
using namespace std;

/*
	Problem Number: 743
	Problem Difficulty: Medium
*/

/*
	Time Complexity: O(Elog(V)) + O(V)
	Space Complexity: O(V + E)
*/
int networkDelayTime(vector<vector<int>> times, int n, int k) {
	vector<pair<int, int>> adj[n + 1];

	for (int i = 0; i < times.size(); i++) {
		adj[times[i][0]].push_back({times[i][1], times[i][2]});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, k});

	vector<int> dist(n + 1, INT_MAX);
	dist[k] = 0;

	while (!pq.empty()) {
		int currDist = pq.top().first;
		int currNode = pq.top().second;
		pq.pop();

		for (auto neighbourNode : adj[currNode]) {
			int nodeToBeReached = neighbourNode.first;
			int weight = neighbourNode.second;

			if (weight + currDist < dist[nodeToBeReached]) {
				dist[nodeToBeReached] = currDist + weight;
				pq.push({dist[nodeToBeReached], nodeToBeReached});
			}
		}
	}

	int maxDelayTime = dist[1];
	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == INT_MAX) return -1;

		maxDelayTime = max(maxDelayTime, dist[i]);
	}

	return maxDelayTime;
}

int main() {

	return 0;
}