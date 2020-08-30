#include <cstdio>
char str[101];

int main() {
	int cnt[26] = { 0, };
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		cnt[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", cnt[i]);
	}
}