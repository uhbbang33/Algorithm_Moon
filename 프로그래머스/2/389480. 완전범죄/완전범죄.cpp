#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    sort(info.begin(), info.end(), [] (vector<int>& q, vector<int>& p){
        if(q[0] - q[1] == p[0] - p[1])
            return q[0]/q[1] > p[0]/p[1];
        else
            return q[0] - q[1] > p[0] - p[1];
    });
    
    int a = 0, b = 0;
    for(int i = 0;i < info.size(); ++i){
        if(b + info[i][1] < m)
            b += info[i][1];
        else if(a + info[i][0] < n)
            a += info[i][0];
        else return -1;
    }
    
    return a;
}