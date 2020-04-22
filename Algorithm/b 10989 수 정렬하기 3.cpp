#include <iostream>
#include <algorithm>
using namespace std;
int cnt[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int max = 0;
	while (n--) {
		int num; cin >> num;
		cnt[num]++;
		if (num > max) max = num;
	}
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << "\n";
		}
	}
}