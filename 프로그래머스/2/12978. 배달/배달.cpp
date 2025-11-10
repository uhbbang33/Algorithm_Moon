#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    int t[51][51]{};
    
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j) continue;
            t[i][j] = INF;
        }
    }

    for(int i = 0; i < road.size(); ++i){
        int start = road[i][0];
        int target = road[i][1];
        int dist = road[i][2];
        
        t[start][target] = min(t[start][target], dist);
        t[target][start] = min(t[target][start], dist);
    }
    
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= N; ++i)
        if(t[1][i] <= K)
            ++answer;
    
    return answer;
}