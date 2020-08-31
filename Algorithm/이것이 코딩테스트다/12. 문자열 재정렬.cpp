#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string solution(string s) {
	int index = 0;
	int sum = 0;
	string answer = "";
	int len = s.length();

	sort(s.begin(), s.end());

	// ������ �հ� ���ڰ� �����ϴ� index ���ϱ� 
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			sum += s[i] - '0';
		}
		else {
			index = i;
			break;
		}
	}

	// ���ڿ��� index���� ������ �߶��� �� �ڿ� sum�� �ٿ��ش�.
	answer = s.substr(index, len - index + 1) + to_string(sum);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << solution(s) << '\n';
}