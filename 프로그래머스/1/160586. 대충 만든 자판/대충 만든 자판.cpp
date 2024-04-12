#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i = 0; i < targets.size(); ++i){
        string curTarget = targets[i];
        answer.push_back(0);
        for(int j = 0; j < curTarget.length(); ++j){
            int minNum = 101;
            for(int k = 0; k < keymap.size(); ++k){
                for(int l = 0; l < keymap[k].length(); ++l){
                    if(keymap[k][l] == curTarget[j]){
                        if(minNum > l)
                            minNum = l+1;
                        break;
                    }
                }
            }
            
            if(minNum <= 100)
                answer[i] += minNum;
            else {
                answer[i] = -1;
                break;
            }
        }
    }
    
    return answer;
}