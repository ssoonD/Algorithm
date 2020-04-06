#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int brown[200001];

int solution(int c, int b) {
	int time = 0;
	bool visit[200001][2];
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	q.push(make_pair(b, 0));
	while (!q.empty()) {
		c += time;
		if (c > 200000) return -1;
		if (visit[c][time % 2]) return time;

		int u = q.front();
		q.pop();
		if (u - 1 >= 0 && brown[u - 1] < 0) {
			brown[u - 1] = brown[u] + 1;
			q.push(u - 1);
		}
		if (u + 1 <= 200000 && brown[u + 1] < 0) {
			brown[u + 1] = brown[u] + 1;
			q.push(u + 1);
		}
		if (2 * u <= 200000 && brown[2 * u] < 0) {
			brown[2 * u] = brown[u] + 1;
			q.push(2 * u);
		}
	}
	int cnt = 1;
	while (c <= 200000) {
		if (brown[c] == cnt) {
			return cnt;
		}
		cnt++;
		c += cnt * (cnt - 1) / 2;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, b; cin >> c >> b;
	cout << solution(c, b) << "\n";
	return 0;
}