#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool visited[11]{};
	bool isRight[11]{};

	int n = 0;
	cin >> n;

	int cow = 0;
	bool temp = false;
	int result = 0;

	for (int i = 0; i < n; ++i) {
		cin >> cow >> temp;
		if (visited[cow] && temp != isRight[cow])
			++result;

		visited[cow] = true;
		isRight[cow] = temp;
	}
	
	cout << result;

	return 0;
}