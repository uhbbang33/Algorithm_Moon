#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	char arr[26]{};
	int curNum = 0;
	bool isFail = false;

	for (int i = 0; i < k; ++i) {
		int s;
		char c;
		cin >> s >> c;

		curNum -= s;
		while (curNum < 0) curNum += n;
		
		if (arr[curNum] == '\0') {
			for (int j = 0; j < n; ++j)
				if (arr[j] == c)
					isFail = true;
			arr[curNum] = c;
		}
		else if (arr[curNum] == c)
			continue;
		else
			isFail = true;
	}

	if (isFail)
		cout << "!";
	else {
		for (int i = 0; i < n; ++i) {
			while (curNum >= n) curNum -= n;

			if (arr[curNum] == '\0')
				cout << "?";
			else
				cout << arr[curNum];
			++curNum;
		}
	}

	return 0;
}