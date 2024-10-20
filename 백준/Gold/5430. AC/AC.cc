#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string p, arr;
		int n;
		cin >> p >> n >> arr;

		deque<int> d;
		string tempStr = "";
		for (int i = 1; i < arr.length() - 1; ++i) {
			if (isalnum(arr[i]))
				tempStr += arr[i];
			if(arr[i] == ',' || i == arr.length() - 2) {
				d.push_back(stoi(tempStr));
				tempStr = "";
			}
		}

		bool RemoveFront = true;
		bool isError = false;
		for (int i = 0; i < p.length(); ++i) {
			if (p[i] == 'R')
				RemoveFront = !RemoveFront;
			else if (p[i] == 'D') {
				if (d.empty()) {
					isError = true;
					break;
				}
				if (RemoveFront)
					d.pop_front();
				else
					d.pop_back();
			}
		}

		if(isError)
			cout << "error" << "\n";
		else {
			cout << "[";
			while(!d.empty()) {
				if (RemoveFront) {
					cout << d.front();
					d.pop_front();
				}
				else {
					cout << d.back();
					d.pop_back();
				}

				if (!d.empty())
					cout << ",";
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}