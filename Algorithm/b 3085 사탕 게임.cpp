#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string board[51];

int solution(int n) {
	int answer = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		// 가로
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
			}
			else {
				answer = max(answer, cnt);
				cnt = 1;
			}
			answer = max(answer, cnt);
		}
		// 세로
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
			}
			else {
				answer = max(cnt, answer);
				cnt = 1;
			}
			answer = max(cnt, answer);
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int result = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			// 위아래
			swap(board[j][i], board[j + 1][i]);
			result = max(result, solution(n));
			swap(board[j][i], board[j + 1][i]);
			// 좌우
			swap(board[i][j], board[i][j + 1]);
			result = max(result, solution(n));
			swap(board[i][j], board[i][j + 1]);
		}
	}
	cout << result << '\n';
}