/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur,
         vector<bool>& vis,
         vector<bool>& stackState,
         const vector<vector<int>>& adj) {

	vis[cur] = true;
	stackState[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not visited, recursively visit the ngb
			if (dfs(ngb, vis, stackState, adj)) {
				return true;
			}
		} else {
			// ngb is visited, check if cur->ngb is a backedge or not
			// to check if cur->ngb is a backedge or not we've check if there is a directed path from ngb to cur
			// to check if there is a directed path from ngb to cur, check if ngb is on the fn call stack while we are at cur
			if (stackState[ngb]) {
				// there is directed from ngb to cur
				// hence cur->ngb is a backedge
				return true;
			}
		}
	}

	stackState[cur] = false;
	return false; // no backedge found in the component of cur node

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> vis(n, false);
	vector<bool> stackState(n, false);
	bool flag =  false; // assume no directed cycle in the graph

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (dfs(i, vis, stackState, adj)) {
				// you've found a cycle in the component of node i hence we've found a cycle in the graph
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "cycle not found" << endl;
	}

	return 0;

}