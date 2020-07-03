#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> que;
	int i = 0;
	for (int day = 0; day != k; day++) {
		if (dates[i] == day) {
			que.push(supplies[i]);
			i++;
		}
		if (!stock) {
			stock += que.top();
			que.pop();
			answer++;
		}
		stock--;
	}
	return answer;
}

int main() {
	int stock = 4;
	vector<int> d = { 4,10,15 };
	vector<int> s = { 20,5,10 };
	int k = 30;
	cout << solution(stock, d, s, k) << '\n';
}