#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };
vector<string> week = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

string solution(int a, int b) {
	string answer = "";
	for (int i = 0; i < a - 1; i++) {
		b += month[i];
	}
	answer = week[b % 7];
	return answer;
}

int main() {
	int a = 5, b = 24;
	cout << solution(a, b);
}