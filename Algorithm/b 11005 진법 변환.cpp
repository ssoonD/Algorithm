#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <char> V;
char conv(int x) {
	if (x <= 9) return x + '0';
	else return x + 'A' - 10;
}
int main() {
	int N, B;
	scanf("%d %d", &N, &B);
	while (N != 0) {
		V.push_back(conv(N % B));
		N /= B;
	}
	while (!V.empty()) {
		printf("%c", V.back());
		V.pop_back();
	}
	return 0;
}