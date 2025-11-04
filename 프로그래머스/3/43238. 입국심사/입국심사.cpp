#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long start = 1, end = (long long)times[0] * n;
    
    
    while(start <= end){
        long long mid = (start + end) / 2;
        long long curNum = 0;
        
        for(int t : times)
            curNum += mid / t;
        
        if(curNum < n)
            start = mid + 1;
        else if(curNum >= n){
            end = mid - 1;
            answer = mid;
        }
    }
    
    return answer;
}