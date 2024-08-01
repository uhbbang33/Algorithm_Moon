#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	unordered_map<string, string> addressMap;
	string address, password;

	for (int i = 0; i < n; ++i) {
		cin >> address >> password;
		addressMap.insert({ address, password });
	}
	for (int i = 0; i < m; ++i) {
		cin >> address;
		cout << addressMap[address] << "\n";
	}

	return 0;
}