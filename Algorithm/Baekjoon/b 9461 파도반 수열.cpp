#include <cstdio>
long long d[101];

long long go(int n) {
	if (d[n] > 0) return d[n];
	return d[n] = go(n - 1) + go(n - 5);
}

int main() {
	int n, t;
	scanf("%d", &t);
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", go(n));
	}
}