#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size());
    
    map<string, int> m;
    
    for(int i = 0; i < name.size(); ++i)
        m.insert({name[i], yearning[i]});
    
    for(int i =0 ; i <photo.size(); ++i)
        for(int j = 0; j < photo[i].size(); ++j)
            answer[i] += m[photo[i][j]];
    
    return answer;
}