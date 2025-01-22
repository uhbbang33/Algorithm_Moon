#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int student;
		cin >> student;
		a.push_back(student);
	}

	int b, c;
	cin >> b >> c;

	long long result = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i] - b;
		int cnt = 1;
		
		if (cur < 0) {
			result += cnt;
			continue;
		}

		cnt += cur / c;
		if (cur % c != 0)
			++cnt;
		
		result += cnt;
	}
	
	cout << result;

	return 0;
}
