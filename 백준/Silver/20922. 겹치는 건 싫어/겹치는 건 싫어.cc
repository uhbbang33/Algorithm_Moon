#include <iostream>
#include <map>
using namespace std;

int arr[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	map<int, int> m;
	int result = 0, curResult = 0;
	int startP = 0;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		++m[arr[i]];

		if (m[arr[i]] > k)
		{
			while (startP < i) {
				--m[arr[startP]];
				--curResult;

				if (arr[startP] == arr[i]) {
					++startP;
					break;
				}
				++startP;
			}
		}
		
		++curResult;
		result = max(result, curResult);
	}

	cout << result;

	return 0;
}