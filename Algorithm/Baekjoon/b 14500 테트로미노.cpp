#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int board[505][505];
bool visit[505][505];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;

int dfs(int x, int y, int cnt) {
	if (cnt == 4) return board[x][y];
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (visit[nx][ny] == false) {
				visit[nx][ny] = true;
				answer = max(answer, dfs(nx, ny, cnt + 1) + board[x][y]);
				visit[nx][ny] = false;
			}
		}
	}
	return answer;
}

//ㅗ모양은 DFS를 사용할 수 없으므로 따로 구해준다.
int exShape(int x, int y) {
	int answer = 0;
	// ㅗ모양
	if (x >= 1 && y >= 1 && y < m - 1)
		answer = max(answer, board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1]);
	// ㅜ모양
	if (x < n - 1 && y >= 1 && y < m - 1)
		answer = max(answer, board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1]);
	// ㅏ모양
	if (x < n - 1 && x >= 1 && y < m - 1)
		answer = max(answer, board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y + 1]);
	// ㅓ모양
	if (x < n - 1 && x >= 1 && y >= 1)
		answer = max(answer, board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y - 1]);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 그점 방문
			visit[i][j] = true;
			answer = max(answer, dfs(i, j, 1));
			answer = max(answer, exShape(i, j));
			// 방문 ㄴㄴ
			visit[i][j] = false;
		}
	}
	cout << answer << '\n';
}