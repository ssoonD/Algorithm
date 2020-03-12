#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int input[100000];
	int result = 0;
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	if (n <= k) {
		result = 1;
	}
	else {
		n -= k;
		k--;
		if (n % k == 0) result = n / k + 1;
		else result = n / k + 2;
	}
	cout << result << '\n';
	return 0;
}