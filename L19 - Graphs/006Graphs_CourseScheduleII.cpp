// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
	vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

		vector<vector<int>> adj(n);
		for (vector<int> pre : prerequisites) {
			int ai = pre[0];
			int bi = pre[1];
			adj[bi].push_back(ai);
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

		vector<int> ans;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			ans.push_back(cur);
			for (int ngb : adj[cur]) {
				indeg[ngb]--;
				if (indeg[ngb] == 0) {
					q.push(ngb);
				}
			}
		}

		return  ans.size() == n ? ans : vector<int>();

	}
};