#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int minCnt = 0;
    int maxCnt = 0;
    
    for(int i = 0; i< lottos.size(); ++i){
        if(lottos[i] == 0){
            ++maxCnt;
            continue;
        }
        for(int j = 0; j < win_nums.size(); ++j)
            if(lottos[i] == win_nums[j]){
                ++minCnt;    
                ++maxCnt;
            }
    }
    
    if(maxCnt == 0) answer.push_back(6);
    else answer.push_back(7-maxCnt);
    
    if(minCnt == 0) answer.push_back(6);
    else answer.push_back(7-minCnt);
    
    return answer;
}