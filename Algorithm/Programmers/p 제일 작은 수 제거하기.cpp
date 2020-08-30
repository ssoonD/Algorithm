#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer = arr;
	int nMin = *min_element(arr.begin(), arr.end());
	int index = find(answer.begin(), answer.end(), nMin) - answer.begin();
	answer.erase(answer.begin() + index);
	return answer.empty() ? vector<int>(1, -1) : answer;
}

int main() {
	vector<int> arr = { 4,3,2,1 };
	for (int i = 0; i < 3; i++) {
		cout << solution(arr)[i] << " ";
	}
	cout << '\n';
}