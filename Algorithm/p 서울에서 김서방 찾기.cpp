#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "�輭���� ";
	int len = seoul.size();
	for (int i = 0; i < len; i++) {
		if (seoul[i] == "Kim") {
			answer += to_string(i);
			break;
		}
	}
	answer += "�� �ִ�";
	return answer;
}

int main() {
	vector<string> seoul = { "Jane","Kim" };
	cout << solution(seoul);
}