#include <iostream>
#include <deque>
using namespace std;

int arr[1000000]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	deque<int> d;
	int curCard = 1;

	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == 1)
			d.push_back(curCard);
		else if (arr[i] == 2) {
			int temp = d.back();
			d.pop_back();
			d.push_back(curCard);
			d.push_back(temp);
		}
		else if (arr[i] == 3)
			d.push_front(curCard);

		++curCard;
	}

	for (int i = n - 1; i >= 0; --i)
		cout << d[i] << " ";

	
	return 0;
}