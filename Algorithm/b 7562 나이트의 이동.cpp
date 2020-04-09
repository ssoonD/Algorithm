#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 300 + 1
int map[MAX][MAX];
int check[MAX][MAX];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int l;

int bfs(int x, int y, int to_x, int to_y) {
	int answer = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = 0;
	if (x == to_x && y == to_y) return answer;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		answer = check[cx][cy] + 1;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx == to_x && ny == to_y) return answer;
			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (check[nx][ny] == -1) {
					q.push({ nx,ny });
					check[nx][ny] = answer;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> l;
		int x, y; cin >> x >> y;
		int to_x, to_y; cin >> to_x >> to_y;
		memset(check, -1, sizeof(check));
		cout << bfs(x, y, to_x, to_y) << "\n";
	}
}