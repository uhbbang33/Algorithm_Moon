#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    // cur, cnt
    queue<pair<int,int>> q;
    q.push({numbers[0], 0});
    q.push({-numbers[0], 0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cnt == numbers.size() - 1){
            if(cur == target)
                ++answer;
            
            continue;
        }
        ++cnt;
        q.push({cur + numbers[cnt], cnt});
        q.push({cur - numbers[cnt], cnt});
    }
    
    
    return answer;
}