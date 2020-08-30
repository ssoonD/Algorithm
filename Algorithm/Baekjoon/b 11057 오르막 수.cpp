/*
D[N][L] = 길이가 N이고 마지막 숫자가 L인 오르막 수의 개수
D[N][L] = hap(D[N-1][K]) (0 <= K <= L)
*/

#include <cstdio>
int d[1001][10];
int mod = 10007;

int main() {
	int n;
	int result = 0;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= mod;
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += d[n][i];
	}
	printf("%d\n", result % mod);
}