#include <deque>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
deque<int> dq;

int solution(int num) {
	int cnt = 0;
	int index = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == num) {
			index = i;
			break;
		}
	}
	if (index < dq.size() - index) {
		for (;;) {
			if (dq.front() == num) {
				dq.pop_front();
				break;
			}
			cnt++;
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	else {
		for (;;) {
			if (dq.front() == num) {
				dq.pop_front();
				break;
			}
			cnt++;
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int result = 0;
	while (m--) {
		int num; cin >> num;
		result += solution(num);
	}
	cout << result << "\n";
}