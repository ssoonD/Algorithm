#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	string tmp;
	getline(cin, tmp);
	while (t--) {
		string cmp, word;
		getline(cin,cmp);
		stringstream ss(cmp);
		while (ss >> word) {
			int len = word.size();
			for (int i = len - 1; i >= 0; i--) {
				cout << word[i];
			}
			cout << " ";
		}
		cout << '\n';
	}
}