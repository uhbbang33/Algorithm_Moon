#include<vector>
#include <queue>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{0,0}, 1});
    maps[0][0] = 0;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m
              || maps[ny][nx] == 0)
                continue;
            
            if(ny == n - 1 && nx == m - 1)
                return cnt + 1;
            
            q.push({{ny, nx}, cnt + 1});
            maps[ny][nx] = 0;
        }
    }
    
    return answer;
}