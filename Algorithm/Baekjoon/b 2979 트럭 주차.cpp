#include <iostream>
#include <algorithm>
using namespace std;
int truck[105];
int price[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int max_num = 0, min_num = 101;
	int answer = 0;
	for (int i = 0; i < 3; i++) {
		int num; cin >> num;
		price[i] = num * (i + 1);
	}
	for (int i = 0; i < 3; i++) {
		int x, y; cin >> x >> y;
		for (int j = x; j < y; j++) {
			truck[j]++;
		}
		if (max_num < y) max_num = y;
		if (x < min_num) min_num = x;
	}
	for (int i = min_num; i < max_num; i++) {
		if (truck[i] == 1) answer += price[0];
		else if (truck[i] == 2) answer += price[1];
		else if (truck[i] == 3) answer += price[2];
	}
	cout << answer << '\n';
}