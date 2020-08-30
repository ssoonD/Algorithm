#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string num; cin >> num;
	int len = num.size();
	long long answer = 0, ten = 1;
	for (int i = 0; i < len - 1; i++) {
		answer += 9 * (i + 1) * ten;
		ten *= 10;
	}
	answer += (stoi(num) - ten + 1) * len;
	cout << answer << '\n';
}