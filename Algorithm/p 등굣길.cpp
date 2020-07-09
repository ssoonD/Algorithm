#include <string>
#include <vector>

using namespace std;

int d[101][101];
bool chk[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	for (auto a : puddles) {
		chk[a[1]][a[0]] = true;
	}
	d[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chk[i][j]) continue;
			else d[i][j] = (d[i - 1][j] + d[i][j - 1]) % 1000000007;
		}
	}
	return d[n][m];
}