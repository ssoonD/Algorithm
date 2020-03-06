#include <cstdio>
#include <algorithm>
using namespace std;

long long count_2(long long num) {
	long long cnt = 0;
	for (long long i = 2; i <= num; i *= 2) {
		cnt += num / i;
	}
	return cnt;
}

long long count_5(long long num) {
	long long cnt = 0;
	for (long long i = 5; i <= num; i *= 5) {
		cnt += num / i;
	}
	return cnt;
}

int main() {
	long long n, m;
	long long res_5 = 0, res_2 = 0;
	scanf("%lld %lld", &n, &m);
	res_5 = count_5(n) - count_5(m) - count_5(n - m);
	res_2 = count_2(n) - count_2(m) - count_2(n - m);
	printf("%lld\n", min(res_2, res_5));
}