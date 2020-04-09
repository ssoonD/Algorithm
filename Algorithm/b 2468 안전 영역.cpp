#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 100 + 1
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };

int solution(bool rain[MAX][MAX], int n, int height) {
	int answer = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!rain[i][j] && !check[i][j]) {
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int idx = 0; idx < 4; idx++) {
						int nx = x + dx[idx];
						int ny = y + dy[idx];
						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							if (!rain[nx][ny] && !check[nx][ny]) {
								q.push({ nx,ny });
								check[nx][ny] = true;
							}
						}
					}
				}
				answer++;
			}
		}
	}
	if (answer == 0) answer = 1;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int max_num = 0, min_num = 101;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			max_num = max(max_num, map[i][j]);
			min_num = min(min_num, map[i][j]);
		}
	}
	for (int k = min_num; k <= max_num; k++) {
		bool rain[MAX][MAX];
		memset(rain, false, sizeof(rain));
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= k) {
					rain[i][j] = true;
				}
			}
		}
		answer = max(answer, solution(rain, n, k));
	}
	cout << answer;
}