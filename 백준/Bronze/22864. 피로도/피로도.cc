#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int cur = 0;
	int time = 0;
	int result = 0;

	while (time < 24) {
		if (cur + a > m){
			cur -= c;
			if (cur < 0)
				cur = 0;
		}
		else {
			cur += a;
			result += b;
		}
		++time;
	}
	cout << result;
	
	return 0;
}