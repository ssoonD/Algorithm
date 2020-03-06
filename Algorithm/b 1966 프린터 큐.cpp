#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cnt = 0;
	int t, n, m, ipt;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			cin >> ipt;
			q.push(make_pair(i, ipt));
			pq.push(ipt);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				++cnt;
				if (index == m) {
					cout << cnt << '\n';
					break;
				}
			}
			else {
				q.push(make_pair(index, value));
			}
		}
	}
}