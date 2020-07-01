#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	map<string, int> person;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		person[name] += 1;
	}
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		person[name] += 1;
	}
	int answer = 0;
	for (auto a : person) {
		if (a.second == 2) {
			answer += 1;
		}
	}
	cout << answer << '\n';
	for (auto a : person) {
		if (a.second == 2) {
			cout << a.first << '\n';
		}
	}
}