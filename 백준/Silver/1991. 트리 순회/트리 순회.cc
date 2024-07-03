#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> m;

void Preorder(char node) {
	if (node == '.') return;
	
	cout << node;
	Preorder(m[node].first);
	Preorder(m[node].second);
}

void Inorder(char node) {
	if (node == '.') return;
	
	Inorder(m[node].first);
	cout << node;
	Inorder(m[node].second);
}

void Postorder(char node) {
	if (node == '.') return;

	Postorder(m[node].first);
	Postorder(m[node].second);
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	char node, left, right;

	for (int i = 0; i < n; ++i) {
		cin >> node >> left >> right;
		m.insert({ node, { left, right }});
	}
	
	Preorder('A');
	cout << "\n";
	Inorder('A');
	cout << "\n";
	Postorder('A');

	return 0;
}