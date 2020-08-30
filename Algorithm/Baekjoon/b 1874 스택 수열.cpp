#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int input[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, j = 0; cin >> n;
	stack<int> s;
	vector<char> v;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for (int i = 1; i <= n; i++) {
		s.push(i);
		v.push_back('+');

		while (!s.empty() && s.top() == input[j]) {
			s.pop();
			v.push_back('-');
			j++;
		}
	}
	if (!s.empty()) cout << "NO" << '\n';
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}
}