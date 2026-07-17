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
	for (int i = 0; i < n; i++) {
		minHeap.insert({dis[i], i});
	}

	// time : VlogV + ElogV ~ (E+V)logV
	// space: V due to ex[] + V due to dis[] + V due to minHeap ~ O(V)

	while (!minHeap.empty()) {

		// pair<int, int> p = *minHeap.begin();
		// int du = p.first;
		// int u = p.second;

		auto [du, u] = *minHeap.begin();
		minHeap.erase(minHeap.begin());


		// for(pair<int, int> p : adj[u]) {
		// 	int v = p.first;
		// 	int edgeWt = p.second;
		// 	...
		// }

		for (auto [v, edgeWt] : adj[u]) {
			if (!ex[v] and dis[v] > dis[u] + edgeWt) {
				// edge between u and v is tensed, so relax it
				auto it = minHeap.find({dis[v], v});
				minHeap.erase(it);
				dis[v] = dis[u] + edgeWt;
				minHeap.insert({dis[v], v});
			}
		}

		ex[u] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis[" << i << "] = " << dis[i] << endl;
	}

	return 0;
}