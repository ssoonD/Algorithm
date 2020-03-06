#include <iostream>
using namespace std;
int d[2005][2005];
int a[2005];

int go(int s, int e) {
	if (s == e) return 1;
	else if (s + 1 == e) {
		if (a[s] == a[e]) return 1;
		else return 0;
	}
	if (d[s][e] > 0)return d[s][e];
	if (a[s] != a[e]) return d[s][e] = 0;
	else return d[s][e] = go(s + 1, e - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << go(s, e) << '\n';
	}
}