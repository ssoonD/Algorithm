#include <iostream>
#include <queue>
using namespace std;
#define MAX 100 + 1

int tomato[MAX][MAX][MAX];
int day[MAX][MAX][MAX];
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
queue<pair<pair<int, int>, int>> q;
int n, m, h;

bool check() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tomato[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

int find_max() {
	int answer = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (answer < day[i][j][k])
					answer = day[i][j][k];
			}
		}
	}
	return answer;
}

int bfs() {
	int answer = 0;
	// 토마토 없으면 -1
	if (q.empty()) {
		return -1;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h) {
				if (tomato[nx][ny][nz] == 0 && day[nx][ny][nz] == -1) {
					tomato[nx][ny][nz] = 1;
					day[nx][ny][nz] = day[x][y][z] + 1;
					q.push({ { nx,ny }, nz });
				}
			}
		}
	}
	if (check()) {
		return find_max();
	}
	else {
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomato[i][j][k];
				day[i][j][k] = -1;
				if (tomato[i][j][k] == 1) {
					day[i][j][k] = 0;
					q.push({ {i,j},k });
				}
			}
		}
	}
	cout << bfs() << '\n';
}