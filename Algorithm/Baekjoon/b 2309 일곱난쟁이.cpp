#include <iostream>
#include <algorithm>
using namespace std;
int dwarf[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int sum = -100;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sort(dwarf, dwarf + 9);
	bool chk = true;
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9; j++) {
			int tmp = dwarf[i] + dwarf[j];
			if (tmp == sum) {
				dwarf[i] = 0;
				dwarf[j] = 0;
				chk = false;
				break;
			}
		}
		if (!chk) break;
	}
	sort(dwarf, dwarf + 9);
	for (int i = 2; i < 9; i++) {
		cout << dwarf[i] << '\n';
	}
}