#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector <string> v;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		v.push_back(str.substr(i, len - i));
	}
	sort(v.begin(), v.end());
	for (auto& i : v) {
		cout << i << '\n';
	}
}