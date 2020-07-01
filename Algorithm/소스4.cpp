#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int map[26][26];
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

int visit(vector<vector<int>> board, int dir, int x, int y) {
	int n = board.size();
	if (map[n - 1][n - 1] != 0) {
		return map[n - 1][n - 1];
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (board[nx][ny] == 0) {
				if (i == dir) {
					map[nx][ny] = map[x][y] + 100;
					visit(board, i, nx, ny);
				}
				else {
					map[nx][ny] = map[x][y] + 600;
					visit(board, i, nx, ny);
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	cout << visit(board, 0, 0, 0);
	cout << map[board.size() - 1][board.size() - 1];
	return answer;
}

int main() {
	//vector<vector<int>> board = { {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0} };
	vector<vector<int>> board = { {0,0,0},{0,0,0},{0,0,0} };
	cout << solution(board);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << map[i][j]<<" ";
		}
		cout << '\n';
	}
}