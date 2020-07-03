#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

struct oper {
	int p; // 연산자 우선순위
	char o; // 연산자
};

stack<long long> numbers;
stack<oper> ex;
vector<int> v = { 1,2,3 };

void calc() {
	long long first = 0, second = 0, result = 0;
	second = numbers.top();
	numbers.pop();
	first = numbers.top();
	numbers.pop();
	char oper = ex.top().o;
	ex.pop();
	if (oper == '*')
		result = first * second;
	else if (oper == '+')
		result = first + second;
	else
		result = first - second;
	numbers.push(result);
}

long long find(string expression) {
	long long result = 0;
	stringstream ss(expression);
	// 우선 순위 0,1,2;
	long long num;
	while (ss >> num) {
		char tmp = ss.get();
		numbers.push(num);
		if (tmp == '*' || tmp == '+' || tmp == '-') {
			int prior;
			if (tmp == '*')
				prior = v[0];
			else if (tmp == '+')
				prior = v[1];
			else
				prior = v[2];
			while (!ex.empty() && prior <= ex.top().p)
				calc();
			ex.push({ prior,tmp });
		}
	}
	while (!ex.empty()) {
		calc();
	}
	result = numbers.top();
	numbers.pop();
	return abs(result);
}

long long solution(string expression) {
	long long answer = 0;
	do {
		if (answer < find(expression)) {
			answer = find(expression);
		}
	} while (next_permutation(v.begin(), v.end()));
	return answer;
}

int main() {
	string ex = "2-2-2-2-2";
	cout << solution(ex);
}