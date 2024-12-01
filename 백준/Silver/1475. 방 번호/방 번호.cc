#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int arr[10]{};
	for (int i = 0; i < s.length(); ++i)
		++arr[s[i] - '0'];

	arr[6] = (arr[6] + arr[9] + 1) / 2;

	int result = 0;
	for (int i = 0; i < 9; ++i) 
		result = max(result, arr[i]);

	cout << result;

	return 0;
}