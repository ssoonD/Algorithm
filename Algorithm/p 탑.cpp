#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	int towerNum = heights.size();
	vector<int> answer(towerNum);
	for (int i = towerNum - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (heights[i] <= heights[j]) {
				answer[i] = j + 1;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> heights = { 1,5,3,6,7,6,5 };
	for (int i = 0; i < solution(heights).size(); i++) {
		cout << solution(heights)[i];
	}
}