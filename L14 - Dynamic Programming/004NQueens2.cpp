/*

https://leetcode.com/problems/n-queens/

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example
	Input : N = 4
	Output:
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10

*/

class Solution {
public:

	void f(int n,
	       vector<string>& board,
	       vector<vector<string>>& allBoards,
	       int i,
	       vector<bool>& columnStatus,
	       vector<bool>& rightDiagStatus,
	       vector<bool>& leftDiagStatus) {

		// base case
		if (i == n) {
			allBoards.push_back(board);
			return;
		}

		// recursive case

		// f(i) : place queens i to n-1

		// decide for Qi

		for (int j = 0; j < n; j++) {
			if (columnStatus[j] == false and
			        rightDiagStatus[(i + j)] == false and
			        leftDiagStatus[(i - j) + (n - 1)] == false) {
				board[i][j] = 'Q';
				columnStatus[j] = true;
				rightDiagStatus[(i + j)] = true;
				leftDiagStatus[(i - j) + (n - 1)] = true;
				f(n, board, allBoards, i + 1, columnStatus, rightDiagStatus, leftDiagStatus);
				board[i][j] = '.'; // backtracking
				columnStatus[j] = false;
				rightDiagStatus[(i + j)] = false;
				leftDiagStatus[(i - j) + (n - 1)] = false;
			}
		}

	}

	vector<vector<string>> solveNQueens(int n) {
		vector<string> board;
		for (int i = 0; i < n; i++) {
			string row(n, '.');
			board.push_back(row);
		}
		vector<vector<string>> allBoards;
		vector<bool> columnStatus(n, false);
		vector<bool> rightDiagStatus(2 * n - 1, false);
		vector<bool> leftDiagStatus(2 * n - 1, false);
		f(n, board, allBoards, 0, columnStatus, rightDiagStatus, leftDiagStatus);
		return allBoards;
	}
};