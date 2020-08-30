#include<iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

char map[MAX][MAX];
char map2[MAX][MAX];
bool chk[MAX][MAX];
bool chk2[MAX][MAX];
int answer1 = 0, answer2 = 0;
int n;

void solution(int x, int y, char color) {
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == color && !chk[nx][ny]) {
				solution(nx, ny, color);
			}
		}
	}
}

void solution2(int x, int y, char color) {
	chk2[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map2[nx][ny] == color && !chk2[nx][ny]) {
				solution2(nx, ny, color);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp; cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 'G') map2[i][j] = 'R';
			else map2[i][j] = tmp;
		}
	}

	int cnt = 0;
	char color = map[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				answer1++;
				solution(i, j, map[i][j]);
			}
		}
		for (int j = 0; j < n; j++) {
			if (!chk2[i][j]) {
				answer2++;
				solution2(i, j, map2[i][j]);
			}
		}
	}

	cout << answer1 << " " << answer2 << "\n";
}