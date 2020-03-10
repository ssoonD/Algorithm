#include <iostream>
using namespace std;

long long solution(int w, int h)
{
	long long answer = 0;
	int tmp = 0;
	int x, y;
	for (int i = 1; i <= w; i++) {
		int x = i;
		int y = h * i / w;
		if (y % x == 0) 
			answer += (y - tmp);
		else
			answer += (y - tmp + 1);
		tmp = y;
	}
	return answer;
}

int main() {
	int w, h;
	cin >> w >> h;
	cout << solution(w, h);
}