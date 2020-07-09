#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> make(string s) {
	unordered_map<string, int> answer;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	int len = s.size() - 1;
	for (int i = 0; i < len; i++) {
		if (isalpha(s[i]) && isalpha(s[i + 1])) {
			answer[s.substr(i, 2)]++;
		}
	}
	return answer;
}

int solution(string str1, string str2) {
	unordered_map<string, int> input1 = make(str1);
	unordered_map<string, int> input2 = make(str2);
	int same = 0;
	int sum = 0;
	for (auto& p : input1) {
		same += min(p.second, input2[p.first]);
	}
	for (auto& p : input1) {
		input2[p.first] = max(input2[p.first], p.second);
	}
	for (auto& p : input2) {
		sum += p.second;
	}
	if (same == 0 && sum == 0) return 65536;
	return 65536 * same / sum;
}