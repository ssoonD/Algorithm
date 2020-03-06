/*
D[n] = 2Xn 직사각형을 채우는 방법의 수
D[n] = D[n-1] + 2*D[n-2]
D[0] = 1, D[1] = 1
Top_Down
*/

#include <cstdio>
int d[1001];
int mod = 10007;

int go(int n) {
	if (n < 2) {
		return 1;
	}
	if (d[n] > 0) {
		return d[n];
	}
	d[n] = (go(n - 1) + 2 * go(n - 2)) % mod;
	return d[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", go(n));
}