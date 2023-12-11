#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int date[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    
    int num = b - 1;
    
    for(int i= 0; i < a - 1; ++i)
        num += date[i];
    
    answer = day[num % 7];
        
    return answer;
}