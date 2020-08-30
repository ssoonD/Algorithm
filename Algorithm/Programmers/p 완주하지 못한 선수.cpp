#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int len = completion.size();
	answer = participant[len];
	for (int i = 0; i < len; i++) {
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}
	return answer;
}

int main() {
	vector<string> participant = { "leo","kiki","eden" };
	vector<string> completion = { "eden","kiki" };
	cout << solution(participant, completion);
}