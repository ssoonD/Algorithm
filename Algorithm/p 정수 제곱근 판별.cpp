#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool compare(long long n) {
	return n / (int)sqrt(n) == sqrt(n);
}

long long solution(long long n) {
	long long answer = 0;
	if (compare(n)) {
		answer = (sqrt(n) + 1) * (sqrt(n) + 1);
	}
	else {
		answer = -1;
	}
	return answer;
}

int main() {
	int n = 121;
	cout << solution(n) << '\n';
}