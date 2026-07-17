/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 1e9;

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

	int s = 0;

	vector<bool> vis(n, false);
	vector<int> dis(n, INF);
	vector<int> par(n);
	queue<int> q;

	vis[s] = true;
	dis[s] = 0;
	par[s] = -1;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				dis[ngb] = dis[cur] + 1;
				par[ngb] = cur;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "par[" << i << "] = " << par[i] << endl;
	}

	int d = 8;

	// construct the path from s to d

	vector<int> path = {d};

	while (par[d] != -1) {
		d = par[d];
		path.push_back(d);
	}

	reverse(path.begin(), path.end());

	for (int x : path) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}