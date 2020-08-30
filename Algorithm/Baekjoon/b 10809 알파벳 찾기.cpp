#include <cstdio>
#include <iostream>
using namespace std;
char str[101];

int main() {
	int cnt[26];
	int num = 0;
	fill_n(cnt, 26, -1);
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		num = str[i] - 'a';
		if (cnt[num] == -1) {
			cnt[num] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", cnt[i]);
	}
}