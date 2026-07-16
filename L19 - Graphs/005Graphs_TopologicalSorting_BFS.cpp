/*

Given an directed graph do its topological sorting

	e.g.

	8 14

	0 1
	0 2
	0 3
	1 3
	1 4
	3 2
	3 4
	3 5
	3 6
	3 7
	4 6
	5 2
	6 7
	7 5

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> indeg(n, 0);
	for (int i = 0; i < n; i++) {
		for (int ngb : adj[i]) {
			indeg[ngb]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int ngb : adj[cur]) {
			indeg[ngb]--;
			if (indeg[ngb] == 0) {
				q.push(ngb);
			}
		}
	}

	return 0;

}