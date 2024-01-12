#include <string>
#include <vector>

using namespace std;

string words[4] = {"aya", "ye", "woo", "ma"};
int answer = 0;

bool CanSay(string str, int pos, string lastSubStr) {
     for(int j = 0; j < 4; ++j) {
         string s = str.substr(pos, words[j].length());
         
         if(words[j] == s && lastSubStr != s) {
             pos += s.length();
             
             if(pos == str.length())
                return true;
             if(CanSay(str, pos, s))
                 return true;
         }
    }
    return false;
}

int solution(vector<string> babbling) {

    for(int i = 0; i < babbling.size(); ++i)
        if(CanSay(babbling[i], 0, ""))
            ++answer;
    
    return answer;
}