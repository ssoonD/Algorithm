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

	d[0] = 1; // 0�� ����� ����� �� 1��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {

		}
	}
}

/*
D[N] = N�� ���� �� �ִ� ����� ��
for�� ������!

D[0] = 1
*/