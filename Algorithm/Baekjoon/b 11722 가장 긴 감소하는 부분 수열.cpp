#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] > a[i]) d[i] = max(d[i], d[j]);
		}
		d[i]++;
	}
	printf("%d\n", *max_element(d, d + n + 1));
}