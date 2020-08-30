#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<string> answer;
	unordered_set<string> s;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		s.insert(tmp);
	}
	for (int i = 0; i < m; i++) {
		string tmp; cin >> tmp;
		if (s.find(tmp) != s.end()) {
			answer.push_back(tmp);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto a : answer) {
		cout << a << '\n';
	}
}