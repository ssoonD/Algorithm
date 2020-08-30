#include <string>
#include <vector>
#include <iostream>

using namespace std;

int d[600001];

int solution(int n) {
	d[0] = d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 1000000007;
	}
	return d[n];
}