/*
D[N] = N을 1로 만드는 최소 연산 횟수
(1) D[N/3] + 1
(2) D[N/2] + 1
(3) D[N-1] + 1
= min(1,2,3)
Bottom_Up
*/
#include <cstdio>

int main() {
	int d[1000001];
	int n;
	d[1] = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	printf("%d", d[n]);
}