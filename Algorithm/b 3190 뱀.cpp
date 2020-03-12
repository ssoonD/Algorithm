#include <iostream>
using namespace std;
int board[105][105];
bool apple[105][105];
int n, len = 1;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int solution(int x, int y, int cht, int dir) {
	int answer = 0;
	if (1 <= x && x <= n && 0 <= y && y <= n) {
		int head  = 
	}
	else {
		return answer;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k; cin >> n >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		apple[x][y] = true;
	}
	int l; cin >> l;
	while (l--) {
		int cnt;
		char c;
		cin >> cnt >> c;
		if (c == 'L') {

		}
		else {

		}
	}
}