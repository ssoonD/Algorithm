#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 6
using namespace std;

int k;
int lotto[MAX]; // 출력 로또 배열
int num[13]; // 입력 배열

// idx1은 num의 인덱스 idx2는 lotto의 인덱스
void solution(int idx1, int idx2) {
	// lotto에 6개의 원소가 입력되면 출력
	if (idx2 == MAX) {
		for (int i = 0; i < MAX; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}
	// 6개의 원소 순차적으로 선택하기
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