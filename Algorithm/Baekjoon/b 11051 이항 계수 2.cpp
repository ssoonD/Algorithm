#include <iostream>
using namespace std;
int d[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	d[0][0] = d[1][0] = d[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j < i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] %= 10007;
		}
	}
	cout << d[n][k] << '\n';
}