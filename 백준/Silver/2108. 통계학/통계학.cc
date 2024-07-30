#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int cnt[8001]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> v(n);
	double aver = 0;
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		aver += v[i];
		++cnt[v[i] + 4000];
	}
	sort(v.begin(), v.end());
	
	aver = round(aver / n);
	if (aver == -0) aver = 0;
	cout << aver << "\n";

	cout << v[n / 2] << "\n";

	int max = 0;
	vector<int> maxVec;
	for (int i = 0; i < 8001; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
			maxVec.clear();
			maxVec.push_back(i - 4000);
		}
		else if (cnt[i] == max)
			maxVec.push_back(i - 4000);
	}
	
	if (maxVec.size() > 1) {
		sort(maxVec.begin(), maxVec.end());
		cout << maxVec[1] << "\n";
	}
	else cout << maxVec[0] << "\n";
	

	cout << v[n - 1] - v[0];

	return 0;
}