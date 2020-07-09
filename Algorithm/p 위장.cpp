#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> closet;
	int cSize = clothes.size();
	for (int i = 0; i < cSize; i++) {
		closet[clothes[i][1]]++;
	}
	for (auto& a : closet) {
		answer *= (a.second + 1);
	}
	return answer - 1;
}