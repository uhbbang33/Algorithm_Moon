#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int goalSize = goal.size();
    
    for(int i = 0; i < goalSize; ++i) {
        if(goal[0] == cards1[0]){
            goal.erase(goal.begin());
            cards1.erase(cards1.begin());
        }
        else if(goal[0] == cards2[0]){
            goal.erase(goal.begin());
            cards2.erase(cards2.begin());
        }
        else{
            answer = "No";
            break;
        }
    }
    if(answer == "")
        answer = "Yes";
        
        
    return answer;
}