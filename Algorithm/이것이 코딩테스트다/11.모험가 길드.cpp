#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> adventurers, int n) {
	int answer = 0;
	int index = 0;
	// ���谡 �������� ����
	sort(adventurers.begin(), adventurers.end());
	// �ش� index�� ���谡 ����ŭ index�� ���������ش�
	// �ݺ����� �������� answer�� 1�� ���������ָ� ������ ���Ѵ�. 
	while (index < n) {
		index += adventurers[index];
		answer++;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> adventurers;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		adventurers.push_back(num);
	}

	cout << solution(adventurers, n) << '\n';
}