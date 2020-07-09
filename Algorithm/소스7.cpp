#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	set<int> num;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		num.insert(tmp);
	}

	for (auto a : num) {
		cout << a << " ";
	}
}