#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i =0 ;i < commands.size(); ++i){
        vector<int> tempArray;
        int cnt = commands[i][0] -1;
        for(int j =0 ; j <= commands[i][1] - commands[i][0]; ++j){
            tempArray.push_back(array[cnt]);
            ++cnt;
        }
        sort(tempArray.begin(), tempArray.end());
        answer.push_back(tempArray[commands[i][2] - 1]);
    }
    return answer;
}