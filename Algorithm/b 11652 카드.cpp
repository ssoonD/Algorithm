#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> card;

long long solution(int n) {
	long long answer = card[0];
	int cnt = 1, cnt_max = 0;
	for (int i = 1; i < n; i++) {
		if (card[i] != card[i - 1]) {
			cnt = 1;
		}
		else {
			cnt++;
		}
		if (cnt_max < cnt) {
			cnt_max = cnt;
			answer = card[i - 1];
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;
		card.push_back(num);
	}
	sort(card.begin(), card.end());
	cout << solution(n) << "\n";
}