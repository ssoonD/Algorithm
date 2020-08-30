#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int alpha[26] = { -1, };

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int sSize = skill.size();
	int tSize = skill_trees.size();
	for (int j = 0; j < tSize; j++) {
		string check = skill_trees[j];
		bool chk = true;
		alpha[0] = find(check.begin(), check.end(), skill[0]) - check.begin();
		for (int i = 1; i < sSize; i++) {
			alpha[i] = find(check.begin(), check.end(), skill[i]) - check.begin();
			if (alpha[i - 1] > alpha[i]) {
				chk = false;
				break;
			}
		}
		if (chk) answer++;
	}
	return answer;
}

int main() {
	string skill = "CBDK";
	vector<string> skill_trees = { "CDB", "CB","CXYB","BD","AECD","ABC","AEX","CDB","CBKD","IJCB","LMDK" };
	cout << solution(skill, skill_trees) << '\n';
}