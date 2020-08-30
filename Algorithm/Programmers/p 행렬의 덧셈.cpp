#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int len = arr1.size();
	for (int i = 0; i < len; i++) {
		int len_2 = arr1[i].size();
		vector<int> tmp;
		for (int j = 0; j < len_2; j++) {
			tmp.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(tmp);
	}
	return answer;
}

int main() {
	vector<vector<int>> arr1 = { {1,2},{2,3} };
	vector<vector<int>> arr2 = { {3,4},{5,6} };
	for (int i = 0; i < 2; i++) {
		cout << solution(arr1, arr2)[i][0] << solution(arr1, arr2)[i][1];
	}
}