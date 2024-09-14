#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num = "";
	bool isPalindrome;
	while (cin >> num, num != "0")
	{
		isPalindrome = true;
		for (int i = 0; i < num.length() / 2; ++i) {
			if (num[i] != num[num.length() - i - 1]) {
				isPalindrome = false;
				break;
			}
		}
		if (isPalindrome == true)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
