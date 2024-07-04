#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string num = "";
	cin >> num;
	if (num == "0") {
		cout << "0";
		return 0;
	}

	int nums[3] = { 4, 2, 1 };
	string result = "";

	for (int i = 0; i < num.length(); ++i) {
		int temp = (int)(num[i] - '0');

		for (int j = 0; j < 3; ++j) {
			if (temp - nums[j] >= 0) {
				result += "1";
				temp -= nums[j];
			}
			else result += "0";
		}
	}

	while (result[0] != '1')
		result.erase(result.begin());
	
	cout << result;

	return 0;
}