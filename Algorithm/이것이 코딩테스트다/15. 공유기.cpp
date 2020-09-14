#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int>& wifi, long long mid, int c) {
	int cnt = 1;
	int last = wifi[0];
	for (auto num : wifi) {
		// num - last : ���������� �Ÿ�
		// �Ÿ��� ũ�ų� ������ ���� ���� + ���� �ٲ��ֱ�
		if (num - last >= mid) {
			cnt++;
			last = num;
		}
	}
	return cnt >= c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, c; cin >> n >> c;
	vector<int> wifi(n);
	for (int i = 0; i < n; i++) {
		cin >> wifi[i];
	}
	sort(wifi.begin(), wifi.end());

	// �Ÿ��� ��������!
	// ������ c�� �̻��̸� ����
	long long l = 1, r = wifi[n - 1] - wifi[0];
	long long answer = l;

	while (l <= r) {
		long long mid = (r + l) / 2;
		if (check(wifi, mid, c)) {
			answer = max(answer, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << answer << '\n';
}