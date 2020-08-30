#include <iostream>
using namespace std;
int tree[50][2];

void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(tree[x][0]);
	preorder(tree[x][1]);
}
void inorder(int x) {
	if (x == -1) return;
	inorder(tree[x][0]);
	cout << (char)(x + 'A');
	inorder(tree[x][1]);
}
void postorder(int x) {
	if (x == -1) return;
	postorder(tree[x][0]);
	postorder(tree[x][1]);
	cout << (char)(x + 'A');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right; cin >> node >> left >> right;
		node = node - 'A';
		if (left == '.') {
			tree[node][0] = -1;
		}
		else {
			tree[node][0] = left - 'A';
		}
		if (right == '.') {
			tree[node][1] = -1;
		}
		else {
			tree[node][1] = right - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}