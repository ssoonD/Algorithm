#include <cstdio>

int main() {
	int x, y;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char* week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	scanf("%d %d", &x, &y);
	for (int i = 1; i < x; i++) {
		y += month[i];
	}
	printf("%s\n", week[y % 7]);
}