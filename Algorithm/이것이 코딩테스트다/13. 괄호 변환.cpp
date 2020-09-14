#include <string>
#include <vector>
#include <iostream>
using namespace std;

// �ùٸ� ��ȣ ���ڿ� üũ�ϱ� �� true Ʋ false
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

// u,v ������ -> index ��ȯ 
int div(string w) {
	int chk = 0, index = 0;
	int len = w.size();
	for (int i = 0; i < len; i++) {
		if (w[i] == '(') chk++;
		else chk--;
		if (chk == 0) {
			index += i;
			break;
		}
	}
	return index;
}

// u���� ������ֱ�
string solution(string w) {
	string u = "", v = "";
	string answer = "";
	string tmp = "";

	// break��
	if (w == "") return answer;

	// 2. ���ڿ� �и� 
	int index = div(w);
	u = w.substr(0, index + 1);
	v = w.substr(index + 1);
	int len = u.size();
	// 3. u�� �ùٸ� ���ڿ� 
	if (check(u) == true) {
		answer += u;
		answer += solution(v);
	}
	// 4. u�� �ùٸ��� ���� ���ڿ� 
	else {
		// 4-1
		answer += "(";
		// 4-2
		answer += solution(v);
		// 4-3
		answer += ")";
		// 4-4
		for (int i = 1; i < len - 1; i++) {
			if (u[i] == '(') tmp += ")";
			else tmp += "(";
		}
		answer += tmp;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string w; cin >> w;
	cout << solution(w) << '\n';
}