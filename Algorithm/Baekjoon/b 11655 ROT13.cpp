#include <cstdio>

int main() {
	char str[101];
	fgets(str, 101, stdin);
	for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'm') {
            str[i] = str[i] + 13;
        }
        else if (str[i] >= 'n' && str[i] <= 'z') {
            str[i] = str[i] - 13;
        }
        else if (str[i] >= 'A' && str[i] <= 'M') {
            str[i] = str[i] + 13;
        }
        else if (str[i] >= 'N' && str[i] <= 'Z') {
            str[i] = str[i] - 13;
        }
	}
	printf("%s\n", str);
}