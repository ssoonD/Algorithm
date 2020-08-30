#include <iostream>
#include <string>
#include <stack>

using namespace std;


// () -> 0 [] -> 1
int solution(string str) {
	int len = str.length();
	stack<int> s;
	int answer = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(0);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() == 1) {
				return 0;
			}
			else if (s.top() == 0) {
				s.pop();
				s.push(2);
			}
			else {
				int tmp = 0;
				while (s.top() != 0 && s.top() != 1) {
					tmp += s.top();
					s.pop();
					if (s.empty()) return 0;
				}
				if (s.top() == 1) {
					return 0;
				}
				s.pop();
				s.push(tmp * 2);
			}
		}
		else if (str[i] == '[') {
			s.push(1);
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() == 0) {
				return 0;
			}
			else if (s.top() == 1) {
				s.pop();
				s.push(3);
			}
			else {
				int tmp = 0;
				while (s.top() != 0 && s.top() != 1) {
					tmp += s.top();
					s.pop();
					if (s.empty()) return 0;
				}
				if (s.top() == 0) {
					return 0;
				}
				s.pop();
				s.push(tmp * 3);
			}
		}
	}
	while (!s.empty()) {
		if (s.top() == 0 || s.top() == 1) return 0;
		answer += s.top();
		s.pop();
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	cout << solution(str) << '\n';
}