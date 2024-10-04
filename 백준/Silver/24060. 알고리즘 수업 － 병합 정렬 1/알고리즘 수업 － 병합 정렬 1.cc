#include <iostream>
using namespace std;

int* A;
int* temp;
int cnt = 0;
int result = -1;
int n, k;

void Merge(int a[], int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;
	while (i <= q && j <= r) {
		if (a[i] <= a[j])
			temp[t++] = a[i++];
		else
			temp[t++] = a[j++];
	}
	while (i <= q)
		temp[t++] = a[i++];
	while (j <= r)
		temp[t++] = a[j++];
	i = p;
	t = 1;
	while (i <= r) {
		a[i++] = temp[t++];
		++cnt;
		if (cnt == k) {
			result = a[i - 1];
			break;
		}
	}
}

void Merge_sort(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		Merge_sort(a, p, q);
		Merge_sort(a, q + 1, r);
		Merge(a, p, q, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	A = new int[n + 1];
	temp = new int[n + 1];

	for (int i = 0; i < n; ++i)
		cin >> A[i];

	Merge_sort(A, 0, n - 1);
	cout << result;

	return 0;
}