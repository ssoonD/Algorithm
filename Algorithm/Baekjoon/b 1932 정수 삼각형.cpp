#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 500 + 1
int num[MAX][MAX];
int d[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num[i][j];
		}
	}

	d[0][0] = num[0][0];
	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + num[i][0];
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + num[i][j];
		}
	}

	cout << *max_element(d[n - 1], d[n - 1] + n) << "\n";
}