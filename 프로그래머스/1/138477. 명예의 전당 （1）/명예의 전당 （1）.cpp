#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tempScore;
    
    for(int i = 0; i<score.size(); ++i){
        tempScore.push_back(score[i]);
        sort(tempScore.begin(), tempScore.end(), greater<>());
        
        if(i >= k)
            answer.push_back(tempScore[k -1]);
        else
            answer.push_back(tempScore[tempScore.size() - 1]);
    }
    
    
    
    return answer;
}