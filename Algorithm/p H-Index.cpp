#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int cSize = citations.size();
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < cSize; i++) {
		if (citations[i] <= answer) break;
		answer++;
	}
	return answer;
}

int main() {
	vector<int> c = { 2,2,2,2,2 };
	cout << solution(c) << '\n';
}