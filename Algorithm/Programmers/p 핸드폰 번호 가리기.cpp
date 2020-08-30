#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	int len = phone_number.size() - 4;
	for (int i = 0; i < len; i++) {
		answer += "*";
	}
	answer += phone_number.substr(len, len + 4);
	return answer;
}

int main() {
	string phone_number = "01033334444";
	cout << solution(phone_number) << '\n';
}