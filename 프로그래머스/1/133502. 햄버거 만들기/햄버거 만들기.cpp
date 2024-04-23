#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> v = {-1};
    for(int a : ingredient){
        if(v.back() == 1 && a == 2)
            v.back() = 12;
        else if(v.back() == 12 && a == 3)
            v.back() = 123;
        else if(v.back() == 123 && a == 1){
            v.pop_back();
            ++answer;
        }
        else
            v.push_back(a);
    }
    
    return answer;
}

