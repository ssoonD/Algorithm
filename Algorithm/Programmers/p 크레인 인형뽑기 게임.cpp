#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;
	int mSize = moves.size();
	int bSize = board.size();
	for (int i = 0; i < mSize; i++) {
		int idx = moves[i] - 1;
		for (int j = 0; j < bSize; j++) {
			if (board[j][idx] != 0) {
				if (!basket.empty() && basket.top() == board[j][idx]) {
					basket.pop();
					answer += 2;
				}
				else {
					basket.push(board[j][idx]);
				}
				board[j][idx] = 0;
				break;
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	cout << solution(board, moves);
}