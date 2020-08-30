#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	stringstream ss(dartResult);

	int sum[3] = { 0,0,0 };
	int op[3] = { 1,1,1 };

	int score;
	char bonus;
	char option;

	for (int i = 0; i < 3; i++) {
		ss >> score;
		bonus = ss.get();
		option = ss.get();
		if (option != '*' && option != '#') ss.unget();

		// bonus S D T
		if (bonus == 'S') {
			sum[i] = score;
		}
		else if (bonus == 'D') {
			sum[i] = pow(score, 2);
		}
		else {
			sum[i] = pow(score, 3);
		}

		// option # *
		if (option == '#') {
			op[i] *= -1;
		}
		else if (option == '*') {
			if (i > 0)op[i - 1] *= 2;
			op[i] *= 2;
		}
	}

	for (int i = 0; i < 3; i++) {
		answer += sum[i] * op[i];
	}
	return answer;
}

int main() {
	string s = "1S2D*3T";
	cout << solution(s) << '\n';
}