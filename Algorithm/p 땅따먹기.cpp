#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int h = land.size();
	for (int i = 1; i < h; i++) {
		land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
		land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
		land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
		land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
	}
	answer = *max_element(land[h - 1].begin(), land[h - 1].end());
	return answer;
}

int main() {
	vector<vector<int>> l = { { 1,2,3,5 },{5,6,7,8},{4,3,2,1} };
	cout << solution(l) << '\n';
}