/*
D[N] = ������ N�� �ִ밪
(1) �ȸ���(0�� ����)	-> D[N-1]
(2) ����(1�� ����)	-> D[N-2]+P[N]
(3) ����(2�� ����)	-> D[n-3]+P[N-1]+P[N]
-> max(1,2,3)
D[1] = P[1]
D[2] = P[1] + p[2]
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int d[10001];
int p[10001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	d[0] = 0;
	d[1] = p[1];
	d[2] = p[1] + p[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 1], max(d[i - 2] + p[i], d[i - 3] + p[i] + p[i - 1]));
	}
	printf("%d\n", d[n]);
}