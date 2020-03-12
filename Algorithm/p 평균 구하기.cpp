#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		answer += arr[i];
	}
	return answer / len;
}

int main() {
	vector<int> arr = { 1,2,3,4 };
	cout << solution(arr) << '\n';
}