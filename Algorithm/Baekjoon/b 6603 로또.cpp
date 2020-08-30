#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 6
using namespace std;

int k;
int lotto[MAX]; // ��� �ζ� �迭
int num[13]; // �Է� �迭

// idx1�� num�� �ε��� idx2�� lotto�� �ε���
void solution(int idx1, int idx2) {
	// lotto�� 6���� ���Ұ� �ԷµǸ� ���
	if (idx2 == MAX) {
		for (int i = 0; i < MAX; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}
	// 6���� ���� ���������� �����ϱ�
	for (int i = idx1; i < k; i++) {
		lotto[idx2] = num[i];
		solution(i + 1, idx2 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		solution(0, 0);
		cout << "\n";
	}
}