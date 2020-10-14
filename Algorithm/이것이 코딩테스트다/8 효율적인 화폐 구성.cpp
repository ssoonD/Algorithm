#include <iostream>
#include <string.h>
using namespace std;

int coin[102];
int d[10002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	memset(d, -1, sizeof(d));
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		d[coin[i]] = 1;
	}

	d[0] = 1; // 0을 만드는 경우의 수 1개
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {

		}
	}
}

/*
D[N] = N을 만들 수 있는 경우의 수
for문 돌리자!

D[0] = 1
*/