#include <iostream>
using namespace std;
int map[25][25];
int dice[] = { 0,0,0,0,0,0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m, x, y;

int go(int dir) {
	int tmp = 0;
	int tmp_x = x, tmp_y = y;
	x += dx[dir - 1];
	y += dy[dir - 1];
	// 주사위 이동
	if (0 <= x && x < n && 0 <= y && y < m) {
		switch (dir) {
		case 1:
			tmp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = tmp;
			break;
		case 2:
			tmp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
			break;
		case 3:
			tmp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = tmp;
			break;
		case 4:
			tmp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
			break;
		default:
			break;
		}
		if (map[x][y] == 0) {
			map[x][y] = dice[5];
		}
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		return dice[0];
	}
	else {
		x = tmp_x;
		y = tmp_y;
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (k--) {
		int dir = 0;
		cin >> dir;
		int result = go(dir);
		if (result >= 0) {
			cout << result << '\n';
		}
	}
}