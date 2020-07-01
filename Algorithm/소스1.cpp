#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
pair<int, int> r_hand = { 3,2 }, l_hand = { 3,0 };

string solution(vector<int> numbers, string hand) {
	string answer = "";
	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];
		if (num == 0) num = 11;
		// 왼손 부분
		if (num % 3 == 1) {
			answer += "L";
			l_hand.first = (num - 1) / 3;
			l_hand.second = 0;
		}
		// 오른손 부분
		else if (num % 3 == 0 && num != 0) {
			answer += "R";
			r_hand.first = (num - 1) / 3;
			r_hand.second = 2;
		}
		// 가운데 부분
		else {
			// 거리 구하기
			int r_len = abs(r_hand.first - (num - 1) / 3) + r_hand.second - 1;
			int l_len = abs(l_hand.first - (num - 1) / 3) + 1 - l_hand.second;
			// 거리의 차가 같을 때
			if (r_len == l_len) {
				if (hand == "right") {
					answer += "R";
					r_hand.first = (num - 1) / 3;
					r_hand.second = 1;
				}
				else {
					answer += "L";
					l_hand.first = (num - 1) / 3;
					l_hand.second = 1;
				}
			}
			else if (r_len > l_len) {
				answer += "L";
				l_hand.first = (num - 1) / 3;
				l_hand.second = 1;
			}
			else {
				answer += "R";
				r_hand.first = (num - 1) / 3;
				r_hand.second = 1;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> numbers = { 0,2,0,5,0,8,0 };
	string hand = "right";
	cout << solution(numbers, hand);
}