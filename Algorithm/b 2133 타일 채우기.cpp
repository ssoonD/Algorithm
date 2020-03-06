#include <cstdio>
int d[31];

int main() {
	int n;
	scanf("%d", &n);
	d[0] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = 3 * d[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += 2 * d[j];
		}
	}
	printf("%d\n", d[n]);
}