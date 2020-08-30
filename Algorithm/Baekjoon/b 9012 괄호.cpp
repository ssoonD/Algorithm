#include <cstdio>
char str[51];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%s", &str);
		int cnt = 0;
		for (int i = 0; str[i]; i++) {
			cnt += (str[i] == '(') - (str[i] == ')');
			if (cnt < 0) {
				break;
			}
		}
		if (cnt == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}