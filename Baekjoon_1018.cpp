#include <iostream>
using namespace std;

int main()
{
	char board[51][51] = {};

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int minCount = 100000;
	
	for (int i = 0; i < n - 7; ++i)
	{
		for (int j = 0; j < m - 7; ++j)
		{
			int count = 0, count2 = 0;
			char firstColor = board[i][j];
			
			for (int k = 0; k < 8; ++k)
				for (int l = 0; l < 8; ++l) {
					if ((k + l) % 2 == 1) {
						if (board[i + k][j + l] == 'W')
							++count;
						if (board[i + k][j + l] == 'B')
							++count2;
					}
					if ((k + l) % 2 == 0) {
						if (board[i + k][j + l] == 'B')
							++count;
						if (board[i + k][j + l] == 'W')
							++count2;
					}
				}

			if (count < minCount)
				minCount = count;
			if (count2 < minCount)
				minCount = count2;
		}
	}
	cout << minCount;

	return 0;
}