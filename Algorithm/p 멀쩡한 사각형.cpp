#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long solution(int w, int h) {
	long long answer = (long long)w * h;
	int num = gcd(w, h);
	return answer - num * (w / num + h / num - 1);
}

int main() {
	int w = 100000000;
	int h = 1;
	cout << solution(w, h);
}