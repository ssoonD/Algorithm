#include <iostream>
using namespace std;
int snail[11][11];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int number;

// (x,y) 현재 위치 , dir 현재 방향 , count 현재 길이
void go(int x, int y, int dir, int count) {
	if (count == 0) return;
	for (int i = 0; i < count; i++) {
		number++;
		x += dx[dir];
		y += dy[dir];
		snail[x][y] = number;
	}
	dir = (++dir) % 4;
	for (int i = 0; i < count; i++) {
		number++;
		x += dx[dir];
		y += dy[dir];
		snail[x][y] = number;
	}
	go(x, y, (++dir) % 4, --count);
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "#" << i << '\n';
		int n; cin >> n; number = n;
		for (int i = 0; i < n; i++) {
			snail[0][i] = i + 1;
		}
		go(0, n - 1, 1, n - 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << snail[i][j] << " ";
			}
			cout << '\n';
		}
	}
}