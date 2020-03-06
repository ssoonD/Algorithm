#include <iostream>
using namespace std;

int go(int x) {
	int result = 0;
	while (x > 0) {
		if (x % 2 == 1) result++;
		x /= 2;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x;
	cin >> x;
	cout << go(x) << '\n';
}