/*
D[N][L] = N자리 이친수, 마지막 숫자 L	-> N자리 이친수
D[N][0] = D[N-1][0] + D[N-1][1]			-> D[N] = D[N-1]
D[N][1] = D[N-1][0]						-> D[N] = D[N-2]
										-> D[N] = D[N-1] + D[N-2]
*/

#include <cstdio>
long long d[91];

int main() {
	int n;
	scanf("%d", &n);
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}
	printf("%lld\n", d[n]);
}