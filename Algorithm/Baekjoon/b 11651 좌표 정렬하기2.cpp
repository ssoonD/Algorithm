#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1
pair<int, int> num[MAX];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i].first >> num[i].second;
	}
	sort(num, num + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << num[i].first << " " << num[i].second << "\n";
	}
}