#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<>> minHeap;

	int num = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num;

		if (i == 0) {
			maxHeap.push(num);
			cout << num << "\n";
			continue;
		}
		else if (maxHeap.size() > minHeap.size())
			minHeap.push(num);
		else
			maxHeap.push(num);

		if (maxHeap.top() > minHeap.top())
		{
			int maxTemp = maxHeap.top();
			int minTemp = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			
			maxHeap.push(minTemp);
			minHeap.push(maxTemp);
		}
		
		cout << maxHeap.top() << "\n";
	}

	return 0;
}