#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	long long res = 0;
	int n;
	string s;
	cin >> s >> n;
	int len = s.size();
	for (int i = len - 1; i >= 0; i--) {
		char c = s[i];
		int num = 0;
		if ('A' <= c && c <= 'Z') {
			num = (int)(c - 'A') + 10;
		}
		else {
			num = (int)(c - '0');
		}
		res += pow(n, len - i - 1) * num;
	}
	printf("%lld\n", res);
}