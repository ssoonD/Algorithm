#include <iostream>
using namespace std;

// 최대공약수
int GCD(int a, int b)
{
	if (a % b == 0) return b;
	return GCD(b, a % b);
}
// 최소공배수
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k; cin >> k;
	while (k--) {
		int n, m, x, y; cin >> m >> n >> x >> y;
		int max_year = LCM(m, n);

		while (x <= max_year && (x - 1) % n + 1 != y) {
			x += m;
		}
		if (x > max_year) cout << "-1" << '\n';
		else cout << x << '\n';
	}
}