#include <iostream>
#include <stack>
using namespace std;

int arr[1000001]{};
int result[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	stack<pair<int, int>> s;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		
		while (!s.empty() && s.top().first < arr[i]) {
			result[s.top().second] = arr[i];
			s.pop();
		}

		s.push({arr[i], i});
	}

	for (int i = 0; i < n; ++i) {
		if (result[i] != 0)
			cout << result[i] << " ";
		else
			cout << "-1" << " ";
	}

	return 0;
}