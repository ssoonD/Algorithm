#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int len = arr.size();
	answer.push_back(arr[0]);
	for (int i = 1; i < len ; i++) {
		if (arr[i] != arr[i - 1]) {
			answer.push_back(arr[i]);
		}
	}
	return answer;
}

int main() {
	vector<int> arr = { 1,1,3,3,0,1,1 };
	for (int i = 0; i < 4; i++) {
		cout << solution(arr)[i] << " ";
	}
}