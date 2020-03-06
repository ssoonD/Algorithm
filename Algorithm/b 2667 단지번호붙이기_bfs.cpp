#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int a[30][30];
int group[30][30];
int ax[] = { 0,0,1,-1 };
int ay[] = { -1,1,0,0 };
int n;
int ans[25 * 25];
int cnt = 0;

void bfs(int x, int y) {
	int res = 1;
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	group[x][y] = ++cnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + ax[i];
			int ny = y + ay[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
					res++;
				}
			}
		}
	}
	ans[cnt] = res;
}

int main() {
	scanf("%d", &n);

	// 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && group[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	sort(ans + 1, ans + cnt + 1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
}