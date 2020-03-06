#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char chess[55][55];

int BW(string s) {
	int len = s.size();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			if (s[i] != 'B') cnt++;
		}
		else {
			if (s[i] != 'W') cnt++;
		}
	}
	return cnt;
}

int WB(string s) {
	int len = s.size();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			if (s[i] != 'W') cnt++;
		}
		else {
			if (s[i] != 'B') cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	int result = 64;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt_BW = 0, cnt_WB = 0;
			bool chk = true; //true : BW false : WB
			for (int k = i; k < 8 + i; k++) {
				string s;
				for (int q = j; q < 8 + j; q++) {
					s += chess[k][q];
				}
				if (chk) {
					cnt_BW += BW(s);
					cnt_WB += WB(s);
					chk = false;
				}
				else {
					cnt_BW += WB(s);
					cnt_WB += BW(s);
					chk = true;
				}
			}
			result = min(result, min(cnt_BW, cnt_WB));
		}
	}
	cout << result << '\n';
}