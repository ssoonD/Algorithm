#include <iostream>
#include <algorithm>
using namespace std;
int ball[] = { 0,1,0,0 };

int main() {
	int m;
	cin >> m;
	while (m--) {
		int first, second;
		int arr_first, arr_second;
		cin >> first >> second;
		int tmp = ball[first];
		ball[first] = ball[second];
		ball[second] = tmp;
	}
	cout << find(ball, ball + 4, 1) - ball << '\n';
}