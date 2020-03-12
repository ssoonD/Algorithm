#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {
	return num % 2 == 0 ? "\"Even\"" : "\"Odd\"";
}

int main() {
	int n = 0;
	cout << solution(n) << '\n';
}