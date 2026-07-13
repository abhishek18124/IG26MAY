/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

	e.g.

	16 16

	0 2
	0 3
	1 3
	1 4
	2 5
	3 5
	3 6
	4 6

	7 9
	8 9
	9 10
	9 11

	12 13
	12 14
	13 15
	14 15

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// time : V.const + 2E.const ~ O(V+2E) or O(n + 2m)
// space: V due to vis[] + V due to function call stack ~ O(V)

void dfs(int cur,
         vector<bool>& vis,
         const vector<vector<int>>& adj) {

	vis[cur] = true;
	cout << cur << " ";

	for (int ngb : adj[cur]) {

		if (!vis[ngb]) {
			dfs(ngb, vis, adj);
		}

	}

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int numComp = 0;

	vector<bool> vis(n, false);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "dfs(" << i << ") : ";
			dfs(i, vis, adj);
			numComp++;
			cout << endl;
		}
	}

	cout << "numComp = " << numComp << endl;

	return 0;
}