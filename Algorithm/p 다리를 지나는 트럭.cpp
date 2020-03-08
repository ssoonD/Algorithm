#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> truck;
	queue<int> q;
	truck.assign(truck_weights.size(), 0);

	return answer;
}

int main() {
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10 };
	cout << solution(bridge_length, weight, truck_weights) << '\n';
}