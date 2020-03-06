/*
D[n] = n을 1,2,3의 조합으로 나타내는 방법의 수
D[n] = D[n-1] + D[n-2] + d[n-3]
D[0] = D[1] = 1, D[2] = 2
Top_Down
*/
#include <cstdio>
int d[12];

int go(int n) {
	if (n == 0) {
		return 1;
	}
	if (n <= 2) {
		return n;
	}
	if (d[n] > 0) {
		return d[n];
	}
	d[n] = go(n - 1) + go(n - 2) + go(n - 3);
	return d[n];
}

int main() {
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", go(n));
	}
}