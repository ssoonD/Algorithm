#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001];
int d1[1001];
int d2[1001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	// 증가하는 함수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) d1[i] = max(d1[i], d1[j]);
		}
		d1[i]++;
	}
	reverse(a + 1, a + n + 1);
	// 증가하는 함수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) d2[i] = max(d2[i], d2[j]);
		}
		d2[i]++;
	}
	reverse(d2 + 1, d2 + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d1[i] + d2[i] - 1);
	}
	printf("%d\n", ans);
}