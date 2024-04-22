#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    sort(skip.begin(), skip.end());
    
    string wordList = "";
    
    bool isWord[26] = {};
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < skip.length(); ++j){
            if(('a' + i) == skip[j])
                isWord[i] = true;
        }   
    }
    
    for(int i = 0; i < 26; ++i){
        if(!isWord[i])
            wordList += 'a' +i;
    }
    
    for(int i = 0; i < s.length(); ++i){
        for(int j = 0; j < wordList.length(); ++j){
            if(wordList[j] == s[i]){
                int tempNum = j + index;
                if(tempNum >= wordList.length())
                    tempNum %= wordList.length();
                    
                s[i] = wordList[tempNum];
                break;
            }
        }
    }
    
    return s;
}