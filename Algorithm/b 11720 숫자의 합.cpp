#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int sum = 0;
	while (N--) {
		int num;
		scanf("%1d", &num);
		sum += num;
	}
	printf("%d", sum);
}
