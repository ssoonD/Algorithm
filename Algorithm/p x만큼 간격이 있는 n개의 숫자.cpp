#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;
	for (int i = 1; i <= n; i++) {
		answer.push_back(x * i);
	}
	return answer;
}

int main() {
	int x = 2;
	int n = 5;
	for (int i = 0; i < n; i++) {
		cout << solution(x, n)[i] << " ";
	}
}