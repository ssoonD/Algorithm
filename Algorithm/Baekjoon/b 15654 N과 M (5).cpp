#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int arr[9];
int input[9];
bool visit[9];

void solution(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = input[i];
			solution(cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n + 1);
	solution(0);
}