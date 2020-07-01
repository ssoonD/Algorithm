#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0, idx = 0;
	queue<int> q;
	while (1) {
		answer++;
		if (q.size() == bridge_length) {
			sum -= q.front();
			q.pop();
		}
		if (sum + truck_weights[idx] <= weight) {
			if (idx == truck_weights.size() - 1) {
				answer += bridge_length;
				break;
			}
			q.push(truck_weights[idx]);
			sum += truck_weights[idx];
			idx++;
		}
		else {
			q.push(0);
		}
	}
	return answer;
}

int main() {
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };
	cout << solution(bridge_length, weight, truck_weights) << '\n';
}