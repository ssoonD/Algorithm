#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	int len = strings.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (strings[i][n] < strings[j][n]) {
				string temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
			if (strings[i][n] == strings[j][n]) {
				if (strings[i] < strings[j]) {
					string temp = strings[i];
					strings[i] = strings[j];
					strings[j] = temp;
				}
			}
		}
	}
	// 내일 다시 맑은 정신으로 풀어보자
	return strings;
}

int main() {
	vector<string> strings = { "sun","bed","car" };
	int n = 1;
	for (auto& i : solution(strings, n)) {
		cout << i << " ";
	}
}