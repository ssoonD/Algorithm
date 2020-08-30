#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> tmp;
	int len = s.size();
	tmp.push(s[0]);
	for (int i = 1; i < len; i++) {
		if (!tmp.empty() && s[i] == tmp.top()) tmp.pop();
		else tmp.push(s[i]);
	}
	if (tmp.empty()) answer = 1;
	return answer;
}

int main() {
	string s = "baabaa";
	cout << solution(s);
}