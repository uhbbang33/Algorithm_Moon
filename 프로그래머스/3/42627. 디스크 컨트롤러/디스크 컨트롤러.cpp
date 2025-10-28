#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    sort(jobs.begin(), jobs.end());
    
    int curTime = 0;
    int jobIndex = 0;
    while(!pq.empty() || jobIndex < jobs.size()){
        while(jobIndex < jobs.size() && jobs[jobIndex][0] <= curTime){
            pq.push({jobs[jobIndex][1], jobs[jobIndex][0]});
            ++jobIndex;
        }
        
        if(!pq.empty()){
            int jobTime = pq.top().first;
            int requestTime = pq.top().second;
             pq.pop();
        
            curTime += jobTime;
            answer += curTime - requestTime;
        }
        else{
            curTime = jobs[jobIndex][0];
        }
    }
    
    return answer / jobs.size();
}