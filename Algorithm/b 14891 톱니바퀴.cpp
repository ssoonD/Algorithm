#include <iostream>
#include <cstdio>
#include <string.h>
#include <deque>
using namespace std;
deque<int> first;
deque<int> second;
deque<int> third;
deque<int> fourth;
bool chk_turn[4];

// 입력받기
deque<int> input(deque<int> gear) {
	for (int i = 0; i < 8; i++) {
		char tmp = 0;
		cin >> tmp;
		gear.push_back(tmp - 48);
	}
	return gear;
}

// 회전하기
deque<int> turn(deque<int> gear, int dir) {
	if (dir == 1) {
		int tmp = gear.back();
		gear.pop_back();
		gear.push_front(tmp);
	}
	else {
		int tmp = gear.front();
		gear.pop_front();
		gear.push_back(tmp);
	}
	return gear;
}

void go(int num, int dir) {
	// gear를 방문하지 않았으면 실행
	if (!chk_turn[num - 1]) {
		chk_turn[num - 1] = true;
		switch (num)
		{
		case 1:
			if (first[2] != second[6]) {
				go(2, -dir);
			}
			else {
				chk_turn[1] = true;
			}
			first = turn(first, dir);
			break;
		case 2:
			if (first[2] != second[6]) {
				go(1, -dir);
			}
			else {
				chk_turn[0] = true;
			}
			if (second[2] != third[6]) {
				go(3, -dir);
			}
			else {
				chk_turn[2] = true;
			}
			second = turn(second, dir);
			break;
		case 3:
			if (second[2] != third[6]) {
				go(2, -dir);
			}
			else {
				chk_turn[1] = true;
			}
			if (third[2] != fourth[6]) {
				go(4, -dir);
			}
			else {
				chk_turn[3] = true;
			}
			third = turn(third, dir);
			break;
		case 4:
			if (third[2] != fourth[6]) {
				go(3, -dir);
			}
			else {
				chk_turn[2] = true;
			}
			fourth = turn(fourth, dir);
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
	cin >> k;
	while (k--) {
		cin >> num >> dir;
		memset(chk_turn, false, sizeof(chk_turn));
		go(num, dir);
	}
	if (first[0] == 1) answer += 1;
	if (second[0] == 1) answer += 2;
	if (third[0] == 1) answer += 4;
	if (fourth[0] == 1) answer += 8;
	cout << answer << '\n';
}