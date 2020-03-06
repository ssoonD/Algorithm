#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int first, second;
		scanf("%d %d", &first, &second);
		printf("%d\n", first + second);
	}
}