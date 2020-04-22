#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1

struct Student {
	string name;
	int korean, english, math;
};

bool cmp(Student s1, Student s2) {
	if (s1.korean == s2.korean) {
		if (s1.english == s2.english) {
			if (s1.math == s2.math) {
				return s1.name < s2.name;
			}
			else {
				return s1.math > s2.math;
			}
		}
		else {
			return s1.english < s2.english;
		}
	}
	return s1.korean > s2.korean;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	Student s[MAX];
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].korean >> s[i].english >> s[i].math;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << s[i].name << "\n";
	}
}