#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<double, double>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	double x1 = v[0].first;
	double y1 = v[0].second;

	double result = 0;
	for (int i = 1; i < n-1; ++i) {
		double x2 = v[i].first;
		double y2 = v[i].second;
		double x3 = v[i + 1].first;
		double y3 = v[i + 1].second;

		result += ((x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3)) / 2;
	}

	cout << fixed;
	cout.precision(1);

	cout << abs(result);

	return 0;
}