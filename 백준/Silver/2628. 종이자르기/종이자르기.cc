#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h;
	cin >> w >> h;

	int n;
	cin >> n;

	vector<int> vecW, vecH;
	vecH.push_back(w);
	vecW.push_back(h);
	for (int i = 0; i < n; ++i) {
		bool isH;
		int num;
		cin >> isH >> num;

		if (isH)
			vecH.push_back(num);
		else
			vecW.push_back(num);
	}

	sort(vecW.begin(), vecW.end());
	sort(vecH.begin(), vecH.end());

	int maxW = 0, maxH = 0;
	int last = 0;
	for (int cur : vecW) {
		if (cur - last > maxW) 
			maxW = cur - last;
		last = cur;
	}

	last = 0;
	for (int cur : vecH) {
		if (cur - last > maxH)
			maxH = cur - last;
		last = cur;
	}

	cout << maxH * maxW;

	return 0;
}