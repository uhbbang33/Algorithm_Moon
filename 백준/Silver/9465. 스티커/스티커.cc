#include <iostream>

using namespace std;

int st[2][100001]{};
int dp[2][100001]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;

        for (int j = 0; j < n; ++j)
            cin >> st[0][j];
        for (int j = 0; j < n; ++j)
            cin >> st[1][j];

        if (n == 1) {
            cout << max(st[0][0], st[1][0]) << "\n";
            continue;
        }

        dp[0][0] = st[0][0];
        dp[1][0] = st[1][0];
        dp[0][1] = st[1][0] + st[0][1];
        dp[1][1] = st[0][0] + st[1][1];

        for (int j = 2; j < n; ++j) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + st[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + st[1][j];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << "\n";
    }

    return 0;
}