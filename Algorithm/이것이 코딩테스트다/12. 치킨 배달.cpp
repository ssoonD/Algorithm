#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// ġŲ�� ��� ��ġ ����
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> storage[14];

int n, m;

int solution() {
	// ������ ����� ���� ���� ����
	vector<int> tmp;
	int len_c = chicken.size();
	int len_h = house.size();
	int answer = INT_MAX;

	// ���� �����
	for (int i = 0; i < m; i++) {
		tmp.push_back(1);
	}
	for (int i = 0; i < len_c - m; i++) {
		tmp.push_back(0);
	}
	sort(tmp.begin(), tmp.end());
	do {
		// �Ÿ����� �ּҰ��� ������ ���� ����
		vector<int> dis_min(len_h, INT_MAX);
		for (int i = 0; i < len_c; i++) {
			// ������ ��츶�� �ּҰ� update
			if (tmp[i] == 1) {
				int sum = 0;
				for (int j = 0; j < len_h; j++) {
					dis_min[j] = min(dis_min[j], storage[i][j]);
					sum += dis_min[j];
				}
				answer = min(answer, sum);
			}
		}
	} while (next_permutation(tmp.begin(), tmp.end()));

	return answer;
}

void distance() {
	// ������ �Ÿ��� storage�� ����
	int len_h = house.size();
	int len_c = chicken.size();
	for (int i = 0; i < len_c; i++) {
		for (int j = 0; j < len_h; j++) {
			int dif = abs(chicken[i].first - house[j].first) + abs(chicken[i].second - house[j].second);
			storage[i].push_back(dif);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			if (num == 1) house.push_back({ i,j });
			else if (num == 2) chicken.push_back({ i,j });
		}
	}

	distance();
	cout << solution() << '\n';
}