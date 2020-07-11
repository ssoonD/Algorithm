#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	unordered_map<int, int> num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		num[x]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (num.find(x) == num.end()) v.push_back(0);
		else v.push_back(num[x]);
	}
	for (auto a : v) {
		cout << a << " ";
	}
}