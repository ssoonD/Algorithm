#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000 + 1
long long max_num = 0;
long long tree[MAX];

bool check(long long x, int n, long long m) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (tree[i] > x) {
			cnt += (tree[i] - x);
		}
	}
	return cnt >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; long long m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		max_num = max(max_num, tree[i]);
	}
	long long answer = 0;
	long long l = 0, r = max_num;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid, n, m)) {
			answer = max(answer, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << answer << "\n";
}