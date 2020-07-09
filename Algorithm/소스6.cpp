#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) return s1 > s2;
	return s1.size() > s2.size();
}

bool chk(vector<string> name, string n) {
	for (int i = 0; i < name.size(); i++) {
		string tmp = name[i];
		if (tmp.find(n) != string::npos) {
			return true;
		}
	}
	return false;
}

bool solution(vector<string> n) {
	sort(n.begin(), n.end(), cmp);
	set<string> names;
	vector<string> tmp;

	for (int i = 0; i < n.size(); i++) {
		if (names.find(n[i]) != names.end()) return true;
		else {
			if (chk(tmp, n[i])) return true;
			names.insert(n[i]);
			tmp.push_back(n[i]);
		}
	}
	return false;
}

int main() {
	vector<string> n = { "快林","家快林具" };
	cout << solution(n);
}