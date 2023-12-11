#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int>a, b;
    while(!A.empty()){
        a.push(A.back()), b.push(B.back());
        A.pop_back(), B.pop_back();
    }
    while(!a.empty()){
        if(a.top()<b.top()){
            a.pop(), b.pop(), answer++;
        }
        else a.pop();
    }
    return answer;
}