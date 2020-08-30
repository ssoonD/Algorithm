#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1);
	for (int i = 0; i < lost.size(); i++) {
		students[lost[i] - 1]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		students[reserve[i] - 1]++;
	}
	for (int i = 0; i < n; i++) {
		int front = i - 1;
		int back = i + 1;
		if (students[i] == 0) {
			if (0 <= front && students[front] == 2) {
				students[i] = 1;
				students[front] = 1;
				answer++;
			}
			else if (back < n && students[back] == 2) {
				students[i] = 1;
				students[back] = 1;
				answer++;
			}
		}
		else answer++;
	}
	return answer;
}

int main() {
	int n = 5;
	vector<int> lost = {1,2,3,4,5};
	vector<int> reserve = { 1 };
	cout << solution(n, lost, reserve) << '\n';
}