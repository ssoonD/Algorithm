#include <string>
#include <vector>
#include <iostream>
using namespace std;

string u = "";
string v = "";
// 올바른 괄호 문자열 체크하기 맞 true 틀 false
bool check(string u) {
	int len = u.size();
	int chk = 0;
	for (int i = 0; i < len; i++) {
		if (u[i] == '(') {
			chk++;
		}
		else {
			if (chk == 0) {
				return false;
			}
			else {
				chk--;
			}
		}
	}
	if (chk != 0) return false;
	else return true;
}
// u,v 나누기
void div(string p) {
	u = "";
	v = "";
	int chk = 0, i = 0;
	int len = p.size();
	for (i = 0; i < len; i++) {
		if (p[i] == '(') chk++;
		else chk--;
		u += p[i];
		if (chk == 0) {
			i++;
			break;
		}
	}
	for (int j = i; j < len; j++) {
		v += p[j];
	}
}
// u문자 만들어주기
string solution(string p) {
	string answer = "";
	string tmp = "";
	div(p);
	while (!u.empty()) {
		int len = u.size();
		if (check(u) == true) {
			answer += u;
			answer += solution(v);
		}
		else {
			for (int i = 1; i < len - 1; i++) {
				if (u[i] == '(') tmp += ")";
				else tmp += "(";
			}
			answer += "(";
			answer += solution(v);
			answer += ")";
			answer += tmp;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string p;
	getline(cin, p);
	cout << solution(p) << "\n";
}