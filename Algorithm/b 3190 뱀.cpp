#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int apple[105][105];
int map[105][105];
int time = 0;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, x = 1, y = 1, dir = 0;
deque<pair<int, int>> rw;
queue<pair<int, char>> input;

void solution() {
	while (1) {
		if (!input.empty()) {
			if (time == input.front().first) {
				if (input.front().second == 'D') {
					dir = (++dir) % 4;
				}
				else {
					--dir;
					if (dir == -1) dir = 3;
				}
				input.pop();
			}
		}
		x += dx[dir];
		y += dy[dir];
		if (0 < x && x <= n && 0 < y && y <= n && map[x][y] == 0) {
			map[x][y] = 1;
			rw.push_front(make_pair(x, y));
			if (apple[x][y] == 0) {
				int tail_x = rw.back().first;
				int tail_y = rw.back().second;
				map[tail_x][tail_y] = 0;
				rw.pop_back();
			}
			else {
				apple[x][y] = 0;
			}
			time++;
		}
		else return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k; cin >> n >> k;
	while (k--) {
		int first, second; cin >> first >> second;
		apple[first][second] = 1;
	}
	int l; cin >> l;
	map[1][1] = 1;
	rw.push_back(make_pair(1, 1));
	while (l--) {
		int num;
		char c;
		cin >> num >> c;
		input.push({ num,c });
	}
	solution();
	cout << time + 1 << '\n';
}