#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	int len = seoul.size();
	for (int i = 0; i < len; i++) {
		if (seoul[i] == "Kim") {
			answer += to_string(i);
			break;
		}
	}
	answer += "에 있다";
	return answer;
}

int main() {
	vector<string> seoul = { "Jane","Kim" };
	cout << solution(seoul);
}