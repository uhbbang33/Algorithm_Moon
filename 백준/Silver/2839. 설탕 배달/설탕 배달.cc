#include <iostream>
using namespace std;

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	int f = 0, t = 0;
	int sub = 0;

	for (int i = 0; i <= 1000; ++i)
	{
		sub = N - (5 * i);

		if (sub < 0)
			break;
		else if(sub % 3 == 0){
			f = i;
			t = sub / 3;
		}
	}

	if (f + t == 0)
		cout << "-1";
	else
		cout << f + t;

	return 0;
}
