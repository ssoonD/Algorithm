#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100 + 1
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<int> answer;
int n, m;

void bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (!check[nx][ny] && map[nx][ny] == 0) {
					q.push({ nx,ny });
					check[nx][ny] = true;
					cnt++;
				}
			}
		}
	}
	answer.push_back(cnt);
}

void make_square(int x1, int y1, int x2, int y2) {
	int start_x, end_x;
	int start_y, end_y;
	start_x = min(y1, y2);
	end_x = max(y1, y2);
	start_y = min(x1, x2);
	end_y = max(x1, x2);
	for (int i = m - end_x; i < m - start_x; i++) {
		for (int j = start_y; j < end_y; j++) {
			map[i][j] = 1;
		}
	}
}

void print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k; cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		make_square(x1, y1, x2, y2);
	}
	print();
	cout << "\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && map[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << "\n";
}