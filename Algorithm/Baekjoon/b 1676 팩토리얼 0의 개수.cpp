#include <cstdio>

int main() {
	int n;
	int res = 0;
	scanf("%d", &n);;
	for (int i = 5; i <= n; i *= 5) {
		res += n / i;
	}
	printf("%d\n", res);
}