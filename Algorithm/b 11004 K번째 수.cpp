#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 5000000 + 1
int num[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	nth_element(num, num + k, num + n);
	cout << num[k] << "\n";
}