/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v where u, v are edge endpoints.

input :

5 6
DL CN
DL MU
CN BE
CN HY
MU HY
HY BE

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<string, vector<string>> adj;
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (auto [node, ngblist] : adj) {
		cout << "ngb(" << node << ") : ";
		for (string ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}