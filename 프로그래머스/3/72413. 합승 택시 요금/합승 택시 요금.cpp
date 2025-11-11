#include <string>
#include <vector>

using namespace std;

#define INF 100000000

int graph[201][201]{};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i =0 ; i <= n; ++i)
        for(int j =0 ; j <= n; ++j){
            if(i == j) continue;
            graph[i][j] = INF;
        }
            
    for(int i = 0; i < fares.size(); ++i){
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        
        graph[start][end] = cost;
        graph[end][start] = cost;
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    
    return answer;
}