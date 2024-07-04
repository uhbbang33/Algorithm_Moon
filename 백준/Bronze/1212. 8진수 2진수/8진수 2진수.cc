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

	string result = "";
	for (int i = 0; i < num.length(); ++i) {
		int temp = (int)(num[i] - '0');
		
		if (temp - 4 >= 0) {
			result += "1";
			temp -= 4;
		}
		else result += "0";
		
		if (temp - 2 >= 0) {
			result += "1";
			temp -= 2;
		}
		else result += "0";

		if (temp - 1 >= 0) {
			result += "1";
			temp -= 1;
		}
		else result += "0";
	}


	while (result[0] != '1')
		result.erase(result.begin());
	
	cout << result;

	return 0;
}