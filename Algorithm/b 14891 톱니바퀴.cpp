#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
vector<int> first;
vector<int> second;
vector<int> third;
vector<int> fourth;
int check[4];

// 입력받기
vector<int> input(vector<int> gear) {
	for (int i = 0; i < 8; i++) {
		int tmp = 0;
		scanf_s("%1d", &tmp);
		gear.push_back(tmp);
	}
	return gear;
}

// 회전하기
vector<int> turn(vector<int> gear, int k, int dir) {
	while (k--) {
		vector<int> tmp;
		if (dir == 1) {
			tmp.push_back(gear[7]);
			for (int i = 1; i < 8; i++) {
				tmp.push_back(gear[i - 1]);
			}
		}
		else {
			for (int i = 0; i < 7; i++) {
				tmp.push_back(gear[i + 1]);
			}
			tmp.push_back(gear[0]);
		}
		for (auto& a : tmp) {
			cout << a << " ";
		}
		gear.assign(tmp.begin(), tmp.end());
	}
	return gear;
}

void go(int num, int k, int dir) {
	if (check[num - 1] == 0) {
		switch (num)
		{
		case 1:
			first = turn(first, k, dir);
			check[0] = first[0];
			if (first[2] == second[6]) {
				break;
			}
			else {
				go(2, k, dir);
			}
			break;
		case 2:
			second = turn(second, k, dir);
			check[1] = second[0];
			if (first[6] == second[2]) {
				break;
			}
			else {
				go(1, k, dir);
			}
			if (second[2] == third[6]) {
				break;
			}
			else {
				go(3, k, dir);
			}
			break;
		case 3:
			third = turn(third, k, dir);
			check[2] = third[0];
			if (second[6] == third[2]) {
				break;
			}
			else {
				go(2, k, dir);
			}
			if (third[2] == fourth[6]) {
				break;
			}
			else {
				go(4, k, dir);
			}
			break;
		case 4:
			fourth = turn(fourth, k, dir);
			check[3] = fourth[0];
			if (third[2] == fourth[6]) {
				break;
			}
			else {
				go(3, k, dir);
			}
			break;
		default:
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	first = input(first);
	second = input(second);
	third = input(third);
	fourth = input(fourth);
	int k, num, dir;
	int answer = 0;
	for (int i = 0; i < 8; i++) {
		cout << first[i] << " ";
	}
	cout << '\n';
	cin >> k;
	while (k--) {
		cin >> num >> dir;
		go(num, k, dir);
	}
	if (first[0] == 1) answer += 1;
	if (second[0] == 1) answer += 2;
	if (third[0] == 1) answer += 4;
	if (fourth[0] == 1) answer += 8;
	cout << answer << '\n';

	vector<int> tt = { 1, 0, 0, 0, 0, 0, 0, 1 };
	turn(tt, 1, 1);
	for (auto& a : tt) {
		cout << a << " ";
	}
}