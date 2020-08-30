#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool chk[101][101];

int bfs(int m, int n, vector<vector<int>> picture, int x, int y, int num) {
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({ x,y });
	chk[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (picture[nx][ny] == num && !chk[nx][ny]) {
					chk[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
	return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			chk[i][j] = false;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && !chk[i][j]) {
				max_size_of_one_area = max(max_size_of_one_area,bfs(m, n, picture, i, j, picture[i][j]));
				number_of_area++;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m = 6;
	int n = 4;
	vector<vector<int>> p = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1}, {0,0,0,3},{0,0,0,3} };
	for (auto a : solution(m, n, p)) {
		cout << a << '\n';
	}
}