#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int temp = n / 100;

	cout << temp * 78 << "\n" 
		<< temp * 80 + (temp * 20) / 100 * 78 ;

	return 0;
}