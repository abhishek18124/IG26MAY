// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

	vector<int> dx = {0, 1, 0, -1};
	vector<int> dy = {1, 0, -1, 0};

	// time : O(V + 2E) V = mn in the worst when each cell in the grid is 1 i.e. a node ; E =
	// space: O(V)

	int dfs(int i, int j,
	        vector<vector<bool>>& vis,
	        const vector<vector<int>>& grid) {

		int cnt = 1;

		int m = grid.size();
		int n = grid[0].size();

		vis[i][j] = true;

		// int nx = i;
		// int ny = j + 1;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
		// 	cnt += dfs(nx, ny, vis, grid);
		// }

		// nx = i;
		// ny = j - 1;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
		// 	cnt += dfs(nx, ny, vis, grid);
		// }

		// nx = i - 1;
		// ny = j;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
		// 	cnt += dfs(nx, ny, vis, grid);
		// }

		// nx = i + 1;
		// ny = j;

		// if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
		// 	cnt += dfs(nx, ny, vis, grid);
		// }

		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
				cnt += dfs(nx, ny, vis, grid);
			}
		}

		return cnt;

	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>> vis(m, vector<bool>(n, false));
		int maxSoFar = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {
					maxSoFar = max(maxSoFar, dfs(i, j, vis, grid));
				}
			}
		}
		return maxSoFar;
	}
};