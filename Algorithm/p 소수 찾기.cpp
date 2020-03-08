#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 1000000;
bool check[MAX + 1]; // true: 지워짐, false: 지워지지 않음

int solution(int n) {
	int answer = 0;
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			answer++;
		}
	}
	return answer;
}

int main() {
	int n = 10;
	cout << solution(n);
}