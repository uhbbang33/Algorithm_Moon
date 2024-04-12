#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> myMap;
    
    for(int i = 0; i<keymap.size(); ++i)
        for(int j =0; j < keymap[i].length(); ++j){
            if(myMap.find(keymap[i][j]) == myMap.end())
                myMap.insert(make_pair(keymap[i][j], j + 1));
            else if(myMap[keymap[i][j]] > j+ 1)
               myMap[keymap[i][j]] = j+1;
        }
    
    for(int i = 0; i<targets.size(); ++i){
        answer.push_back(0);
        for(int j = 0; j < targets[i].length(); ++j){
            if(myMap.find(targets[i][j]) == myMap.end()){
                answer[i] = -1;
                break;
            }
            answer[i] += myMap[targets[i][j]];
        }
    }
    
    return answer;
}