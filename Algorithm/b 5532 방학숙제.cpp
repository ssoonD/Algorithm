#include <iostream>
using namespace std;

int day(int a, int c) {
	return a % c == 0 ? a / c : a / c + 1;
}

int main() {
	int l, a, b, c, d;
	int answer = 0;
	cin >> l >> a >> b >> c >> d;
	int korean = day(a, c);
	int math = day(b, d);
	answer = korean > math ? l - korean : l - math;
	cout << answer << '\n';
}