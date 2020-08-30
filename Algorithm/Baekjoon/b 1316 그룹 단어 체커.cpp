#include <iostream>
#include <string>
using namespace std;

int answer = 0;

void solution(string s) {
	bool chk[26] = { false, };
	int len = s.length();
	char c = '\0';
	for (int i = 0; i < len; i++) {
		if (s[i] == c) continue;
		else c = s[i];
		if (chk[s[i] - 'a']) return;
		chk[s[i] - 'a'] = true;

	}
	answer++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		solution(s);
	}
	cout << answer << "\n";
}