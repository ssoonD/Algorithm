#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1002][1002] = {};

int solution(vector<vector<int>> board)
{
	int answer = 0;
	for (int i = 1; i <= board.size(); i++) {
		for (int t = 1; t <= board[0].size(); t++) {
			dp[i][t] = (min(min(dp[i - 1][t], dp[i][t - 1]), dp[i - 1][t - 1]) + 1) *
				board[i - 1][t - 1];
			answer = max(answer, dp[i][t]);
		}
	}
	return answer * answer;
}

int main() {
	vector<vector<int>> b = { { 0,1,1,1 }, { 1,1,1,1 }, { 1,1,1,1 }, { 0,0,1,0 } };
	cout << solution(b) << '\n';
}