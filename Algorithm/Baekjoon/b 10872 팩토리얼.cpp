#include <cstdio>

int main() {
	int n;
	long long res = 1;
	scanf("%d", &n);
	for (int i = n; i > 1; i--) {
		res *= i;
	}
	printf("%lld\n", res);
}