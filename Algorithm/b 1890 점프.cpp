#include <iostream>
using namespace std;
long long d[105][105];
int a[105][105];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) continue;
			// (i,j) -> (i,j+a[i][j])
			if (j + a[i][j] <= n) {
				d[i][j + a[i][j]] += d[i][j];
			}
			// (i,j) -> (i+a[i][j],j)
			if (i + a[i][j] <= n) {
				d[i + a[i][j]][j] += d[i][j];
			}
		}
	}
	cout << d[n][n] << '\n';
	return 0;
}