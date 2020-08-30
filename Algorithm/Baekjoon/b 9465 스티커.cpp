/*
D[i][j] = 2Xi���� ���� �� �ִ� �ִ� ����, i�� ������ ��� ��ƼĿ�� j
j = 0 -> ����	max(D[i-1][1],D[i-1][2]) + A[i][0]
j = 1 -> �Ʒ���	max(D[i-1][0],D[i-1][2]) + A[i][1]
j = 2 -> ���� ����	max(D[i-1][0], max(D[i-1][1],D[i-1][2]))
-> max(D[i][0], max(D[i][1], D[i][2])
*/

#include <cstdio>
#include <algorithm>
using namespace std;
long long d[100001][3];
long long p[100001][2];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int i = 1; i <= n; i++) {
				scanf("%lld", &p[i][j]);
			}
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]) + p[i][0];
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + p[i][1];
			d[i][2] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		}
		printf("%lld\n", max(d[n][0], max(d[n][1], d[n][2])));
	}
}