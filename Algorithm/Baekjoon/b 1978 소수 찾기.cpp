#include <cstdio>

bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		if (prime(num))
			cnt++;
	}
	printf("%d\n", cnt);
}