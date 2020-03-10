#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (const auto& elem : scoville) {
		pq.push(elem);
	}
	while (!pq.empty()) {
		int first = pq.top();
		pq.pop();
		if (first >= K) break;
		if (pq.empty()) return -1;
		int second = pq.top();
		pq.pop();
		pq.push(first + second * 2);
		answer++;
	}
	return answer;
}

int main() {
	vector<int> scoville = { 1,1,1,1 };
	int k = 10;
	cout << solution(scoville, k);
}