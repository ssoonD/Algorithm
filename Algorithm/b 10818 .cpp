#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int num[1000001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	printf("%d %d\n", num[0], num[N - 1]);
}