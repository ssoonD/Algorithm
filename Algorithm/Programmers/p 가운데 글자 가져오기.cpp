#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
	string answer = "";
	int len = s.size();
	if (len % 2 == 0) {
		answer = s.substr(len / 2 - 1, 2);
	}
	else {
		answer = s[len / 2];
	}
	return answer;
}

int main() {
	string s = "abcde";
	cout << solution(s) << '\n';
}