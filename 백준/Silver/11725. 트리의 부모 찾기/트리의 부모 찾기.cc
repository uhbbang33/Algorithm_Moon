#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100001

int n = 0;
int answer[MAX]{};
vector<int> graph[MAX]{};
bool visited[MAX]{};

void bfs() {
    visited[1] = true;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < graph[parent].size(); ++i) {
            int child = graph[parent][i];
            if (!visited[child]) {
                answer[child] = parent;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    int x, y = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs();

    for (int i = 2; i <= n; ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}