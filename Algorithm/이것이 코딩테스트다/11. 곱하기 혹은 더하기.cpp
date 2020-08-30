#include <iostream>
#include <string>
using namespace std;

long long solution(string s) {
	int len = s.size();
	long long answer = 0;
	for (int i = 0; i < len; i++) {
		// value�� 0�϶��� �Ѿ
		if (s[i] == '0') continue;
		// 1�� ���� �����ֱ�
		else if (s[i] == '1') answer += 1;
		else {
			// 1���� �۰ų� ���� ���� �����ִ°� �̵�
			if (answer <= 1) answer += (s[i] - '0');
			// �ƴ϶�� �����ֱ�!
			else answer *= (s[i] - '0');
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << solution(s) << '\n';
}