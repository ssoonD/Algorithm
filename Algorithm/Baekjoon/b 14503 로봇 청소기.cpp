#include <iostream>
#include <vector>
using namespace std;
int map[55][55];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
int cnt = 1;

int go(int r, int c, int d) {
	if (0 < r && r < n - 1 && 0 < c && c < m - 1) {
		map[r][c] = -1;
		for (int i = 0; i < 4; i++) {
			// 왼쪽 판별
			d = (d + 3) % 4;
			int x = r + dx[d];
			int y = c + dy[d];
			// 청소할 공간이 있을 때
			if (map[x][y] == 0) {
				cnt++;
				return go(x, y, d);
			}
		}
		// 후진할 위치 정하기
		switch (d)
		{
		case 0: r++; break;
		case 1: c--; break;
		case 2: r--; break;
		case 3: c++; break;
		default:
			break;
		}
		if (map[r][c] == 1)
			return cnt;
		else return go(r, c, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << go(r, c, d) << '\n';
}