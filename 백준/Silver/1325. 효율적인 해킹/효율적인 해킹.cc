#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, m;
vector<int> graph[10001]{};
int result[10001]{};
bool visited[10001]{};
int hackNum = 0;

void DFS(int x) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); ++i) {
        int child = graph[x][i];

        if (!visited[child]) {
            DFS(child);
            ++hackNum;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int num1, num2;
    for (int i = 0; i < m; ++i) {
        cin >> num1 >> num2;
        graph[num2].push_back(num1);
    }

    int maxResult = 0;
    for (int i = 1; i <= n; ++i) {
        hackNum = 0;
        if (!visited[i]) {
            DFS(i);
            result[i] = hackNum;
        }

        if (hackNum > maxResult)
            maxResult = hackNum;

        for (int j = 1; j <= n; ++j)
            visited[j] = false;
    }

    for (int i = 1; i <= n; ++i)
        if (maxResult == result[i])
            cout << i << " ";

    return 0;
}
