#include <cstdio>
#include <cstring>
char str[5005];
int d[5005];
int mod = 1000000;

int main() {
	scanf("%s", &str[1]);
	int n = strlen(&str[1]);
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x = str[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] = (d[i] + d[i - 1]) % mod;
		}
		if (i == 1) continue;
		if (str[i - 1] == '0') continue;
		x = (str[i - 1] - '0') * 10 + (str[i] - '0');
		if (10 <= x && x <= 26) {
			d[i] = (d[i] + d[i - 2]) % mod;
		}
	}
	printf("%d\n", d[n]);
}