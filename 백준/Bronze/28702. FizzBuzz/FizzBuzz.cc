#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string arr[3]{};

	int num = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
		if (!isalpha(arr[i][0]))
			num = stoi(arr[i]) + (3 - i);
	}

	string resultString = "";
	if (num % 3 == 0)
		resultString += "Fizz";
	if (num % 5 == 0)
		resultString += "Buzz";
	if (resultString == "")
		resultString = to_string(num);

	cout << resultString;


	return 0;
}