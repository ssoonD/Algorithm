#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	while (n > 0) {
		answer.push_back(n % 10);
		n /= 10;
	}
	return answer;
}

int main() {
	long long n = 12345;
	for (int i = 0; i < 5; i++) {
		cout << solution(n)[i] << '\n';
	}
}