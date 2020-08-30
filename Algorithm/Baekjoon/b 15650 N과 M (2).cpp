#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int arr[9];
bool visit[9];

void solution(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = cnt == 0 ? 1 : arr[cnt - 1] + 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			solution(cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	solution(0);
}