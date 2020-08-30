#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int d[200001], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(d, -1, sizeof(d));
	int n, k; cin >> n >> k;
	queue<int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty() && d[k] < 0) {
		int u = q.front();
		q.pop();
		if (u - 1 >= 0 && d[u - 1] < 0) {
			d[u - 1] = d[u] + 1;
			q.push(u - 1);
		}
		if (u + 1 <= 2 * k && d[u + 1] < 0) {
			d[u + 1] = d[u] + 1;
			q.push(u + 1);
		}
		if (2 * u <= 2 * k && d[2 * u] < 0) {
			d[2 * u] = d[u] + 1;
			q.push(2 * u);
		}
	}
	cout << d[k] << "\n";
	return 0;
}