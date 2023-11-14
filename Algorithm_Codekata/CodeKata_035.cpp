//https://school.programmers.co.kr/learn/courses/30/lessons/82612
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money;

    for (int i = 1; i <= count; ++i)
        answer -= i * price;
    if (answer < 0)
        answer *= -1;
    else
        answer = 0;

    return answer;
}