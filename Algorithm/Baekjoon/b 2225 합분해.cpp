/*
D[N][K] = 0~N���� ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ��
D[N][K] += D[N-L][K-1] (0<=L<=N)
*/

#include <cstdio>
long long d[201][201];
long long mod = 1000000000;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	d[0][0] = 1LL;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int p = 0; p <= i; p++) {
				d[i][j] += d[i - p][j - 1];
				d[i][j] %= mod;
			}
		}
	}
	printf("%lld\n", d[n][k]);
}