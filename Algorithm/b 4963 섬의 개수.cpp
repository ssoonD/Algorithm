#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[55][55];
int d[55][55];
int ax[] = { -1,-1,-1,0,0,1,1,1 };
int ay[] = { -1,0,1,-1,1,-1,0,1 };
int w, h;
int cnt = 0;

void bfs(int x, int y, int cnt) {
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + ax[i];
			int ny = y + ay[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	while (1) {
		int cnt = 0;
		scanf("%d %d", &h, &w);
		if (w == 0 && h == 0) break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%d", &a[i][j]);
				d[i][j] = 0;
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (d[i][j] != 0) {
				}
			}
		}
		printf("%d\n", cnt);
	}
}