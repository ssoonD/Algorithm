#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
	string answer = "";
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) answer += "¼ö";
		else answer += "¹Ú";
	}
	return answer;
}

int main() {
	int n = 4;
	cout << solution(n);
}