#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 0;
	cin >> n;
	
	int temp = 0;
	int num;
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		
		if (i == 1)
			max = num;

		if (num >= temp + num)
			temp = num;
		else
			temp = temp + num;

		if (temp > max)
			max = temp;
	}

	cout << max;

	return 0;
}