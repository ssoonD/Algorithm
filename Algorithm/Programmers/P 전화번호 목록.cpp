#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());
	string first, second;
	int len = phone_book.size();
	for (int i = 0; i < len - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
	}
	return true;
}

int main() {
	vector<string> phone_book = { "97674223","1195524421","119"};
	cout << solution(phone_book) << '\n';
}