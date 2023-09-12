#include <iostream>
#include <algorithm>
using namespace std;

pair<int, string> member[100001] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> member[i].first >> member[i].second;

	stable_sort(member, member + n, 
		[](pair<int, string> a, pair<int, string> b){
			if (a.first < b.first)
				return true;
			return false;
		});

	for (int i = 0; i < n; ++i)
		cout << member[i].first << " " << member[i].second << '\n';
	
	return 0;
}