#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int cards[101] = {};
	for (int i = 0; i < N; ++i)
		cin >> cards[i];

	int maxResult = 0;
	
	for (int i = 0; i < N; ++i)
	{
		int result = 0;

		for (int j = i + 1; j < N; ++j)
			for (int k = j + 1; k < N; ++k) {
				result = cards[i] + cards[j] + cards[k];

				if (maxResult < result && result <= M)
					maxResult = result;
			}
	}

	cout << maxResult;

	return 0;
}
