#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<>> pq;

	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		pq.push(num);
	}

	int result = 0;
	for (int i = 0; i < n-1; ++i) {
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		
		pq.push(temp);
		result += temp;
	}

	cout << result;


	return 0;
}