#include <iostream>
using namespace std;

long long solution(long long x, long long y) {
	long long answer = 0;
	long long num = y - x;
	long long n = 1;
	while (n * n - n + 1 <= num) {
		n++;
	}
	n--;
	if (num <= n * n) {
		answer = 2 * n - 1;
	}
	else {
		answer = 2 * n;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--) {
		long long x, y; cin >> x >> y;
		cout << solution(x, y) << '\n';
	}
}