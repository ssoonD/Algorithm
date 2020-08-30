#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int k; cin >> k;
	stack<int> s;
	int answer = 0;

	while (k--) {
		int n; cin >> n;
		if (n != 0) {
			s.push(n);
		}
		else {
			s.pop();
		}
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	cout << answer << '\n';
}