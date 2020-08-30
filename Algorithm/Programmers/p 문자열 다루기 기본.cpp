#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
	bool answer = true;
	int len = s.size();
	if (len != 4 && len != 6) {
		answer = false;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (s[i] < '0' || s[i] > '9') {
				answer = false;
				break;
			}
		}
	}
	return answer;
}

int main() {
	string s = "a1234";
	cout << solution(s);
}