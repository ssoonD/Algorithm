#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		cout << x + y << '\n';
	}
}