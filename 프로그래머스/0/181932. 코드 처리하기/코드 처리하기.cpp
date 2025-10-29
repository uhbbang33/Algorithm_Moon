#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool mode = false;
    int idx = 0;
    for(char c : code){
        if(!mode){
            if(c != '1' && idx % 2 == 0)
                answer += c;
            else if(c == '1')
                mode = true;
        }
        else{
            if(c != '1' && idx % 2 == 1)
                answer += c;
            else if(c == '1')
                mode = false;
        }
        ++idx;
    }
    
    if(answer == "")
        answer = "EMPTY";
    
    return answer;
}