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

	int temp = arr[9] + arr[6];
	if (temp % 2 == 0)
		arr[6] = temp / 2;
	else
		arr[6] = temp / 2 + 1;

	int result = 0;
	for (int i = 0; i < 9; ++i) 
		result = max(result, arr[i]);

	cout << result;

	return 0;
}