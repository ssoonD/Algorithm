#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 8

using namespace std;

int n, m, answer = 0;
int map[MAX][MAX];
int temp_map[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// 지도 복사 
void copy_map(int(*a)[MAX], int(*b)[MAX]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

// 바이러스 뿌리기
void spread_virus() {
	int spread_map[MAX][MAX];
	copy_map(spread_map, temp_map);
	queue<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spread_map[i][j] == 2) {
				virus.push(make_pair(i, j));
			}
		}
	}

	while (!virus.empty()) {
		int x = virus.front().first;
		int y = virus.front().second;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 범위 안에 포함된다면
				if (spread_map[nx][ny] == 0) {
					spread_map[nx][ny] = 2;
					virus.push(make_pair(nx, ny));
				}
			}
		}
	}

	int cnt_empty = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spread_map[i][j] == 0) {
				cnt_empty++;
			}
		}
	}
	answer = max(answer, cnt_empty);
}

void make_wall(int cnt_wall) {
	// 벽을 3개 만들었을 때
	if (cnt_wall == 3) {
		spread_virus();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_map[i][j] == 0) {
				temp_map[i][j] = 1;
				make_wall(cnt_wall + 1);
				temp_map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				copy_map(temp_map, map);
				temp_map[i][j] = 1;
				make_wall(1);
				temp_map[i][j] = 0;
			}
		}
	}
	cout << answer << "\n";
}