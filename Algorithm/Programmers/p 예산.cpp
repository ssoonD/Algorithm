#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int sum = 0;
	sort(d.begin(), d.end());
	for (auto num : d) {
		sum += num;
		if (sum <= budget) {
			answer++;
		}
		else {
			break;
		}
	}
	return answer;
}

int main() {
	vector<int> d = { 2,2,3,3 };
	int budget = 10;
	cout << solution(d, budget) << '\n';
}