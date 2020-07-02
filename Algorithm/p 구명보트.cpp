#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 1;
	sort(people.begin(), people.end());
	int pSize = people.size();
	int sum = 0;
	for (int i = 0; i < pSize; i++) {
		sum += people[i];
		if (sum == limit) {
			answer++;
			sum = 0;
		}
		else if (limit < sum) {
			answer++;
			sum = people[i];
		}
	}
	return answer;
}

int main() {
	vector<int> p = { 70,50,80,50 };
	int l = 100;
	cout << solution(p, l) << '\n';
}