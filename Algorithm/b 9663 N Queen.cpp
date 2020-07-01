#include <iostream>
using namespace std;
int n;
int chess[20];
int answer = 0;

bool check(int num) {

}

void solution(int num) {
	if (num == n) {
		answer++;
	}
	else {
		for (int i = 0; i < n; i++) {
			chess[num] = i;
		}
	}
}

int main() {
	cin >> n;
	solution(0);
	cout << answer << '\n';
}