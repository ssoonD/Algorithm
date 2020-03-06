#include <cstdio>

int main() {
	int T, A, B;
	char c;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %c %d", &A, &c, &B);
		printf("%d\n", A + B);
	}
}