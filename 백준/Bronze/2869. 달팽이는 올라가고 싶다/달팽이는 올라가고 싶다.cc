#include <iostream>
using namespace std;

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B, V;
	cin >> A >> B >> V;

	int N = 0;
	int C = A - B;

	N = (V-A) / C;

	while (1) {
		if (C * N + A >= V || C * ++N >= V)
			break;
	}

	cout << N + 1;

    return 0;
}
