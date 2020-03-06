#include <cstdio>
const int MAX = 1000000;
bool check[MAX + 1]; // true: 지워짐, false: 지워지지 않음

int main() {
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	while (1) {
		int num;
		scanf("%d", &num);
		if (num == 0) break;
		for (int i = 3; i < num; i += 2) {
			if (!check[num - i] && !check[i]) {
				printf("%d = %d + %d\n", num, i, num - i);
				break;
			}
		}
	}
}