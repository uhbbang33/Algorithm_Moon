#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int XCount[10] = {};
    int YCount[10] = {};
    
    for(int i = 0; i < X.size(); ++i)
        ++XCount[X[i] - 48];
    for(int i = 0; i < Y.size(); ++i)
        ++YCount[Y[i] - 48];
    
    for(int i = 9; i >= 0; --i){
        while(XCount[i] > 0 && YCount[i] > 0){
            answer += (i + 48);
            
            --XCount[i];
            --YCount[i];
        }
    }

    if(answer == "") answer = "-1";
    else if(answer[0] == '0') answer = "0";
    
    return answer;
}