#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int num[8];
int tmp[8];

void solution(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << tmp[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = cnt == 0 ? 1 : num[cnt - 1]; i <= n; i++) {
		num[cnt] = i;
		solution(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	solution(0);
}