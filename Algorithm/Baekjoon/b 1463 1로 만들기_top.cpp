/* 
D[N] = N을 1로 만드는 최소 연산 횟수
(1) D[N/3] + 1
(2) D[N/2] + 1
(3) D[N-1] + 1
= min(1,2,3)
Top_Down
*/

#include <cstdio>
int d[1000001];

int go(int n) {
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int tmp = go(n / 2) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	if (n % 3 == 0) {
		int tmp = go(n / 3) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	return d[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", go(n));
}