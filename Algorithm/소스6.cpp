#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 10000000;
bool check[MAX + 1]; // true: ������, false: �������� ����

// �����佺�׳��� ü
void chk(int n) {
	check[0] = check[1] = true;
	for (int i = 2; i * i <= n; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
}

int solution(int n) {
	int answer = 0;
	
	return answer;
}

int main() {
	int n = 10;
	cout << solution(n);
}