/*
D[n] = n을 1,2,3의 조합으로 나타내는 방법의 수
D[n] = D[n-1] + D[n-2] + d[n-3]
D[0] = D[1] = 1, D[2] = 2
Bottom_Up
*/
#include <cstdio>
int d[12];

int main() {
	int n, t;
	d[0] = d[1] = 1;
	d[2] = 2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
}