#include <iostream>
#include <map>
using namespace std;

int arr[200001]{};
int cnt[200001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int result = 0, curResult = 0;
	int startP = 0;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		++cnt[arr[i]];

		if (cnt[arr[i]] > k)
		{
			while (startP < i) {
				--cnt[arr[startP]];
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