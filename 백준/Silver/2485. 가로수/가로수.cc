#include <iostream>
using namespace std;

int arr[100001]{};
int dist[100001]{};

int GCD(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (i > 0)
			dist[i] = (arr[i] - arr[i - 1]);
	}

	int gcd = GCD(max(dist[1], dist[2]), min(dist[1], dist[2]));
	for (int i = 3; i < n; ++i) {
		int temp = GCD(max(gcd, dist[i]), min(gcd, dist[i]));
		gcd = min(temp, gcd);
	}

	int result = 0;
	for (int i = 1; i < n; ++i)
		result += dist[i] / gcd - 1;

	cout << result;

	return 0;
}