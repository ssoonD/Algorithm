#include <cstdio>

int main() {
	char str[101];
	while (gets_s(str)) {
		int cnt[4] = { 0, };
		for (int i = 0; str[i]; i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				cnt[0]++;
			}
			else if ('A' <= str[i] && str[i] <= 'Z') {
				cnt[1]++;
			}
			else if ('0' <= str[i] && str[i] <= '9') {
				cnt[2]++;
			}
			else if (str[i] == ' ') {
				cnt[3]++;
			}
		}
		for (int a : cnt) {
			printf("%d ", a);
		}
		printf("\n");
	}
}