#include <cstdio>
#include <algorithm>
using namespace std;
int d[301];
int p[301];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	d[1] = p[1];
	d[2] = p[1] + p[2];
	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + p[i], d[i - 3] + p[i] + p[i - 1]);
	}
	printf("%d\n", d[n]);
}