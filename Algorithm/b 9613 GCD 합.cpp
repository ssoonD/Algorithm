#include <cstdio>
int num[105];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		long long result = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				result += gcd(num[i], num[j]);
			}
		}
		printf("%lld\n", result);
	}
}