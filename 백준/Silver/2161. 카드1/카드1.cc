#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	deque<int> d;
	for (int i = 1; i <= n; ++i)
		d.push_back(i);

	while (d.size() > 1) {
		cout << d.front() << " ";
		d.pop_front();

		d.push_back(d.front());
		d.pop_front();
	}
	
	cout << d.front();
	

	return 0;
}