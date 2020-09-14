#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Virus {
public:
	int index;
	int x;
	int y;
	Virus(int index, int x, int y) {
		this->index = index;
		this->x = x;
		this->y = y;
	}
	// 정렬 기준은 '번호가 낮은 순서'
	bool operator < (Virus& other) {
		return this->index < other.index;
	}
};

int n, k;
int s, x, y;
// 전체 정보를 담는 배열
int map[205][205];
// time을 담는 배열
int time[205][205];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> q;
vector<Virus> viruses;

int bfs() {
	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (map[nx][ny] == 0) {
					q.push({ nx,ny });
					map[nx][ny] = map[now_x][now_y];
					time[nx][ny] = time[now_x][now_y]++;
					if (time[now_x][now_y] == (s + 1)) return map[x - 1][y - 1];
				}
			}
		}
	}
	return map[x - 1][y - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				viruses.push_back(Virus(map[i][j], i, j));
			}
		}
	}
	cin >> s >> x >> y;

	int len = viruses.size();
	for (int i = 0; i < len; i++) {
		q.push({ viruses[i].x, viruses[i].y });
	}

	cout << bfs() << '\n';
}