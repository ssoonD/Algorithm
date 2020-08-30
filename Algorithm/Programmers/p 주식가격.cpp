#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int len = prices.size();
	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = i + 1; j < len; j++) {
			cnt++;
			if (prices[i] > prices[j]) break;
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	vector<int> prices = { 1,2,3,2,3,4,5 };
	for (int i = 0; i < 7; i++) {
		cout << solution(prices)[i];
	}
}