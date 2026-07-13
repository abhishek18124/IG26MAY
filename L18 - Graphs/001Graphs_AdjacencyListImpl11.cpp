/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (1 <= u, v <= n) where u, v are edge endpoints .

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	// vector<vector<int>> adj(n + 1); // 0th index is not used

	// for (int i = 0; i < m; i++) {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	adj[u].push_back(v);
	// 	adj[v].push_back(u);
	// }

	// for (int i = 1; i <= n; i++) {
	// 	cout << "ngb(" << i << ") : ";
	// 	vector<int> ngblist = adj[i];
	// 	for (int ngb : ngblist) {
	// 		cout << ngb << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // to convert the problem into 0-based indexing
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		vector<int> ngblist = adj[i];
		for (int ngb : ngblist) {
			cout << ngb + 1 << " ";
		}
		cout << endl;
	}

	return 0;

}