/*
D[N][L]= 길이가 n이고 마지막 숫자가 L인 계단 수의 개수
D[N] = D[N-1][L-1] + D[n-1][L+1]
*/

#include <cstdio>
long long d[101][10];
long long mod = 1000000000;


int main() {
	int n;
	long long result = 0;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j > 0) { 
				d[i][j] += d[i - 1][j - 1]; 
			}
			if (j < 9) { 
				d[i][j] += d[i - 1][j + 1]; 
			}
			d[i][j] %= mod;
		}
	}
	for (int i = 0; i <= 9; i++) {
		result += d[n][i];
	}
	printf("%lld\n", result % mod);
}