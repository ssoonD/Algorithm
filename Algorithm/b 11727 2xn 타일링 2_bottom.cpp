/*
D[n] = 2Xn 직사각형을 채우는 방법의 수
D[n] = D[n-1] + 2*D[n-2]
D[0] = 1, D[1] = 1
Bottom_Up
*/

#include <cstdio>
int d[1001];

int main() {
	int n;
	scanf("%d", &n);
	d[1] = d[0] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 2 * d[i - 2];
		d[i] %= 10007;
	}
	printf("%d\n", d[n] % 10007);
}