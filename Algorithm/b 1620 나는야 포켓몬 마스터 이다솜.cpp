#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<string, int>> pkm;
vector<pair<string, int>> memo;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name; cin >> name;
		pkm.push_back({ name,i });
		memo.push_back({ name,i });
	}
	sort(memo.begin(), memo.end(), cmp);
	while (m--) {
		string s; cin >> s;
		if ('0' <= s[0] && s[0] <= '9') {
			cout << pkm[stoi(s) - 1].first << '\n';
		}
		else {
			int l = 0, r = n;
			while (l <= r) {
				int mid = (r + l) / 2;
				if (s == memo[mid].first) {
					cout << memo[mid].second << '\n';
					break;
				}
				if (s < memo[mid].first) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
		}
	}
}