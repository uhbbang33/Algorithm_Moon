#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int nums[3]{};
	nums[0] = (s[0] - '0') * 10 + s[1] - '0';
	nums[1] = (s[3] - '0') * 10 + s[4] - '0';
	nums[2] = (s[6] - '0') * 10 + s[7] - '0';
	
	if ((nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
		|| nums[0] > 59 || nums[1] > 59 || nums[2] > 59) {
		cout << "0";
		return 0;
	}

	int result = 0;
	for (int i = 0; i < 3; ++i)
		if (nums[i] <= 12 && nums[i] > 0)
			result += 2;

	cout << result;

	return 0;
}