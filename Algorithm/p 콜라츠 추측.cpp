#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
	int answer = 0;
	long long number = num;
	while (number != 1) {
		if (answer == 500) {
			answer = -1;
			break;
		}
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = 3 * number + 1;
		}
		answer++;
	}
	return answer;
}

int main() {
	int n = 626331;
	cout << solution(n) << '\n';
}