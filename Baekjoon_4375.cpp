#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;	// 자릿수
	int n = 0;		// 입력받은 숫자

	while (cin >> n) {
		int ans = 1;
		cnt = 1;
		
		while (1) {
			if (ans % n == 0)
				break;
			else {
				++cnt;
				ans = ans * 10 + 1;
				ans %= n;
				// mod연산을 통해 너무 커지는 숫자를 줄일 수 있음
			}
		}
		cout << cnt << endl;
	}

	return 0;
}

// https://www.acmicpc.net/problem/4375