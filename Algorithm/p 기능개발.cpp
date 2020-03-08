#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	int len = progresses.size();
	for (int i = 0; i < len; i++) {
		int val_pro = progresses[i];
		int val_sp = speeds[i];
		int tmp = 0;
		while (val_pro < 100) {
			val_pro += val_sp;
			tmp++;
		}
		day.push_back(tmp);
	}
	int num = day[0];
	int cnt = 1;
	for (int i = 1; i < len; i++) {
		if (day[i] <= num) {
			cnt++;
		}
		else {
			num = day[i];
			answer.push_back(cnt);
			cnt = 1;
		}
		if (i == len - 1) {
			answer.push_back(cnt);
		}
	}
	return answer;
}

int main() {
	vector<int> progresses, speeds;
	progresses = { 93,30,55 };
	speeds = { 1,30,5 };
	for (auto a : solution(progresses, speeds))
		cout << a;
	return 0;
}