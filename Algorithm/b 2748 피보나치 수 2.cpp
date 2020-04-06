#include <iostream>
using namespace std;

long long memo[90];

long long fb(int n) {
	if (n <= 1)
		return n;
	else {
		if (memo[n] > 0)
			return memo[n];
		else {
			memo[n] = fb(n - 1) + fb(n - 2);
			return memo[n];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cout << fb(n) << "\n";
}