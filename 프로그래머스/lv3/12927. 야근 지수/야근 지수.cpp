#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int>q;
long long solution(int n, vector<int> works) {
    for(auto e : works) q.push(e);
    int x;
    long long answer = 0;
    while(n--){
        if(q.empty()) break;
        x = q.top(); q.pop();
        x--;
        if(x) q.push(x);
    }
    while(!q.empty()){
        x = q.top(); q.pop();
        answer += pow(x,2);
    }
    return answer;
}