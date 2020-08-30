#include <iostream>
using namespace std;

int main() {
	int in, out;
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int tmp = 0;
		cin >> out >> in;
		if (in == 0) break;
		tmp = result + in - out;
		if (result < tmp) result = tmp;
	}
	cout << result << '\n';
}