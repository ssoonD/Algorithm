#include <cstdio>
#include <cmath>
using namespace std;
int check[1000000];

int next(int a, int p) {
	int num = 0;
	while (a > 0) {
		num += pow(a % 10, p);
		a /= 10;
	}
	return num;
}

int length(int a, int p, int cnt) {
	if (check[a] != 0) {
		return check[a] - 1;
	}
	check[a] = cnt;
	return length(next(a, p), p, cnt + 1);
}

int main() {
	int a, p;
	scanf("%d %d", &a, &p);
	printf("%d\n", length(a, p, 1));
}