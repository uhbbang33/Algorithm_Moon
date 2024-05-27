#include <iostream>
#include <vector>

using namespace std;

int dp[1000]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    int num = 0;
    vector<int> v;
    v.push_back(0);

    int max = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        v.push_back(num);

        dp[i] = num;

        int tempMax = 0;
        for (int j = i - 1; j >= 1; --j)
            if (v[i] > v[j] && tempMax < dp[j])
                tempMax = dp[j];

        dp[i] = tempMax + v[i];

        if (max < dp[i])
            max = dp[i];
    }

    cout << max;

    return 0;
}