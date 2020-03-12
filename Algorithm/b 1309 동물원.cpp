#include <iostream>
using namespace std;
int lion[100005];
int mod = 9901;

int main() {
	int n;
	cin >> n;
	lion[0] = 1;
	lion[1] = 3;
	for (int i = 2; i <= n; i++) {
		lion[i] = 3 * lion[i - 2] + 2 * (lion[i - 1] - lion[i - 2]);
		lion[i] %= 9901;
	}
	cout << lion[n] << '\n';
}