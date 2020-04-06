#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000 + 1
int color[MAX][3];
int d[MAX][3];

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		d[0][i] = color[0][i];
	}

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + color[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + color[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + color[i][2];
	}
	cout << min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2])) << "\n";
}