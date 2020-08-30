#include <iostream>

using namespace std;

int coin[] = { 500,100,50,10,5,1 };

int solution(int pay) {
	int tmp = 1000 - pay;
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		while (tmp - coin[i] >= 0) {
			tmp -= coin[i];
			cnt++;
			if (tmp == 0) break;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int pay; cin >> pay;
	cout << solution(pay) << '\n';
}