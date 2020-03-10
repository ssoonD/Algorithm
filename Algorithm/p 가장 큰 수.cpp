#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> v;
	int len = numbers.size();
	for (auto& elem : numbers) {
		v.push_back(to_string(elem));
	}
	sort(v.begin(), v.end(), compare);
	if (v[0] == "0") answer = "0";
	else {
		for (int i = 0; i < len; i++) {
			answer += v[i];
		}
	}
	return answer;
}

int main() {
	vector<int> numbers = { 3,30,34,5,9 };
	cout << solution(numbers) << '\n';
}