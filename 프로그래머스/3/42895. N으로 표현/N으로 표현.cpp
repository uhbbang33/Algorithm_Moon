#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> dp[9];
    
    int num = 0;
    for(int i = 1 ; i <= 8; ++i){
        num = 10 * num + N;
        dp[i].insert(num);
    }
    
    for(int i = 2; i <= 8; ++i){
        for(int j = 1; j <= i; ++j){
            for(int a : dp[j]){
                for(int b : dp[i - j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0)
                        dp[i].insert(a / b);
                }
            }
        }
    }
    
    for(int i = 1; i <= 8; ++i){
        if(dp[i].find(number) != dp[i].end()){
            answer = i;
            break;
        }
    }
    
    
    return answer;
}