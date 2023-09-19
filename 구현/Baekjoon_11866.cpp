#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		v[i] = i+1;
	
	cout << "<";
	int iter = 0;

	while (v.size() > 0) {
		iter = (iter + k - 1) % n;
		n -= 1;

		cout << v[iter];

		v.erase(v.begin() + iter);
		v.shrink_to_fit();
		
		if (v.size() > 0)
			cout << ", ";
	}
	cout << ">";

	return 0;
}