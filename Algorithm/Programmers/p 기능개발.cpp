#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	int pSize = progresses.size();
	for (int i = 0; i < pSize; i++) {
		day.push_back(ceil((100 - progresses[i]) / speeds[i]));
	}
	int num = day[0], cnt = 1;
	for (int i = 1; i < pSize; i++) {
		if (num < day[i]) {
			answer.push_back(cnt);
			cnt = 1;
			num = day[i];
		}
		else {
			cnt++;
		}
	}
	answer.push_back(cnt);
	return answer;
}

int main() {
	vector<int> pro = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };
	for (auto a : solution(pro, speeds)) {
		cout << a << '\n';
	}
}