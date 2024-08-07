#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	queue<int> q;

	int fruit = 0;
	int resultCnt = 0;
	int fruitCnt[10]{};
	int type = 0; 

	for (int i = 0; i < n; ++i) {
		cin >> fruit;
		q.push(fruit);

		if (fruitCnt[fruit] == 0)
			++type;
		++fruitCnt[fruit];

		while (type > 2) {
			int tempFruit = q.front();

			--fruitCnt[tempFruit];
			q.pop();

			if (fruitCnt[tempFruit] == 0)
				--type;
		}
		resultCnt = max(resultCnt, (int)q.size());
	}

	cout << resultCnt;

	return 0;
}