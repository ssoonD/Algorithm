#include <cstdio>

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int num = gcd(a, b);
	printf("%d\n", num);
	printf("%d\n", a * b / num);
}