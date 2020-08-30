#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000 + 1

long long ls[MAX];

// cnt가 더 크니 = 숫자가 더 작니?
bool check(long long x, int k, int n) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += ls[i] / x;
	}
	return cnt >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k, n; cin >> k >> n;
	long long max_num = 0;
	for (int i = 0; i < k; i++) {
		cin >> ls[i];
		max_num = max(max_num, ls[i]);
	}
	long long answer = 0;
	long long l = 1, r = max_num;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid, k, n)) {
			answer = max(answer, mid);
			l = mid + 1;
		} 
		else {
			r = mid - 1;
		}
	}
	cout << answer << "\n";
}