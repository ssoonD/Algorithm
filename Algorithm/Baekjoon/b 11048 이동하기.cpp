#include <iostream>
#include <algorithm>
using namespace std;
int d[1005][1005];
int a[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}
	cout << d[n][m] << '\n';
	return 0;
}