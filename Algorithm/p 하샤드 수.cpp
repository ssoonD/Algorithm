#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
	int answer = x, tmp = 0;
	while (x > 0) {
		tmp += x % 10;
		x /= 10;
	}
	return answer % tmp == 0 ? true : false;
}

int main() {
	int x = 13;
	cout << solution(x) << '\n';
}