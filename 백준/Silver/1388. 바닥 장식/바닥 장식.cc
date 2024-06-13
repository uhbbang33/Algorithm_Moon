#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
bool visited[51][51]{};
vector<char> graph[51]{};
int result = 0;

void DFS(int y, int x) {
    visited[y][x] = true;
    char c = graph[y][x];
    
    if (c == '-') {
        if (x + 1 < m && graph[y][x + 1] == '-' && !visited[y][x + 1])
            DFS(y, x + 1);
    }
    else if (c == '|') {
        if (y + 1 < n && graph[y + 1][x] == '|' && !visited[y + 1][x])
            DFS(y + 1, x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            graph[i].push_back(c);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                ++result;
                DFS(i, j);
            }
        }
    }

    cout << result;

    return 0;
}
