#include <iostream>
#include <vector>
using namespace std;

#define MAX_LOTTO 6

int k = 0;
int arr[13]{};

void SelectNum(int index, vector<int> v) {
	if (v.size() == MAX_LOTTO) {
		for (int i = 0; i < MAX_LOTTO; ++i)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i < k; ++i) {
		v.push_back(arr[i]);
		SelectNum(i + 1, v);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; ++i)
			cin >> arr[i];

		vector<int> v;
		SelectNum(0, v);

		cout << "\n";
	}

	return 0;
}