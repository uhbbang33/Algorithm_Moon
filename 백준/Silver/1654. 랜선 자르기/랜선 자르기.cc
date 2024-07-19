#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	vector<int> lines(k);
	for (int i = 0; i < k; ++i)
		cin >> lines[i];
	sort(lines.begin(), lines.end());

	long long maxLength = 0;
	long long start = 1;
	long long end = lines[k - 1];
	int sum = 0;

	while (start <= end) {
		maxLength = (start + end) / 2;
		sum = 0;

		for (int i = 0; i < lines.size(); ++i)
			sum += lines[i] / maxLength;

		if (sum >= n)
			start = maxLength + 1;
		else
			end = maxLength - 1;
	}

	if (sum < n && maxLength != 0)
		--maxLength;

	cout << maxLength;

	return 0;
}