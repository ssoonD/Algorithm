#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string str) {
	int len = str.length();
	stack<int> s;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '{') {
			s.push(0);
		}
		else {
			if (s.empty()) {
				cnt++;
				s.push(0);
			}
			else {
				s.pop();
			}
		}
	}
	cnt += s.size() / 2;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 1;; i++) {
		string str; cin >> str;
		if (str[0] == '-') break;
		cout << i << ". " << solution(str) << '\n';
	}
}
