#include <iostream>
using namespace std;

bool lights[4001] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> lights[i];

	int num = 0, first = 0, second = 0;
	for (int i = 0; i < m; ++i) {
		cin >> num >> first >> second;
		first -= 1;
		second -= 1;

		if (num == 1)
			lights[first] = second+1;
		else if (num == 2)
			for (int j = first; j <= second; ++j)
				lights[j] = !lights[j];
		else if (num == 3) 
			for (int j = first; j <= second; ++j)
				lights[j] = false;
		else if (num == 4)
			for (int j = first; j <= second; ++j)
				lights[j] = true;
	}
	
	for (int i = 0; i < n; ++i)
		cout << lights[i] << " ";

	return 0;
}