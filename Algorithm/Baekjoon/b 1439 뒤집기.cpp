#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
	int len = s.length();
	int cnt = 1;
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) cnt++;
	}
	return cnt / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << solution(s) << '\n';
}