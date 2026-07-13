/*

Implementation of graph search using

  depth first search   (dfs)

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

  int s = 0;
  vector<bool> vis(n, false);

  dfs(s, vis, adj);

  return 0;

}