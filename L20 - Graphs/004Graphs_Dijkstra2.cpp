/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> dis(n, INF);
	dis[s] = 0;

	vector<bool> ex(n, false);
	set<pair<int, int>> minHeap;
	minHeap.insert({dis[s], s});

	vector<int> par(n);
	par[s] = -1;

	// time : VlogV + ElogV ~ (E+V)logV
	// space: V due to ex[] + V due to dis[] + V due to minHeap ~ O(V)

	while (!minHeap.empty()) {

		auto [du, u] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		for (auto [v, edgeWt] : adj[u]) {
			if (!ex[v] and dis[v] > dis[u] + edgeWt) {
				// edge between u and v is tensed, so relax it
				par[v] = u;
				minHeap.erase({dis[v], v});
				dis[v] = dis[u] + edgeWt;
				minHeap.insert({dis[v], v});
			}
		}

		ex[u] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << endl;
	}

	int d = 3;

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