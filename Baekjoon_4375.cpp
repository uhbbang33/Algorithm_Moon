#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;	// �ڸ���
	int n = 0;		// �Է¹��� ����

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
				// mod������ ���� �ʹ� Ŀ���� ���ڸ� ���� �� ����
			}
		}
		cout << cnt << endl;
	}

	return 0;
}

// https://www.acmicpc.net/problem/4375