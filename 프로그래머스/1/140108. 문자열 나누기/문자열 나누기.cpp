#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    char firstChar = s[0];
    int firstWordNum = 1;
    int otherWordNum = 0;
    
    for(int i = 1; i < s.length(); ++i){
        if(s[i] == firstChar){
            ++firstWordNum;
            continue;
        }
        
        ++otherWordNum;
        
        if(firstWordNum == otherWordNum && i != s.length() - 1)
        {
            firstWordNum = 1;
            otherWordNum = 0;
            firstChar = s[i+1];
            ++i;
            ++answer;
        }
    }
    
    ++answer;
    return answer;
}