#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int tSize = triangle.size();
	for (int i = 1; i < tSize; i++) {
		int len = triangle.size();
		for (int j = 0; j < len; j++) {
			if (j == 0) triangle[i][j] += triangle[i - 1][j];
			else if (j == len - 1) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}
	answer = *max_element(triangle[tSize - 1].begin(), triangle[tSize - 1].end());
	return answer;
}