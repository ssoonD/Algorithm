#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100001];
long long d[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = max(a[i], d[i - 1] + a[i]);
	}
	printf("%lld\n", *max_element(d + 1, d + n + 1));
}