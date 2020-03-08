#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> one = { 1,2,3,4,5 };
	vector<int> two = { 2,1,2,3,2,4,2,5 };
	vector<int> three = { 3,3,1,1,2,2,4,4,5,5 };
	vector<int> they(3);
	int len = answers.size();
	for (int i = 0; i < len; i++) {
		if (answers[i] == one[i % 5]) {
			they[0]++;
		}
		if (answers[i] == two[i % 8]) {
			they[1]++;
		}
		if (answers[i] == three[i % 10]) {
			they[2]++;
		}
	}
	int winner = *max_element(they.begin(), they.end());
	for (int i = 0; i < 3; i++) {
		if (they[i] == winner) answer.push_back(i + 1);
	}
	return answer;
}

int main() {
	vector<int> answers = { 1,3,2,4,2 };
	for (int i = 0; i < solution(answers).size(); i++) {
		cout << solution(answers)[i] << " ";
	}
}