#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<string,string>p;
int main(){
    int n;
    string x, y;
    cin >> n;
    priority_queue<p, vector<p>, greater<p>>q;
    priority_queue<string, vector<string>, greater<string>>ans;
    while(n--){
        cin >> x >> y;
        q.push({x,y});
    }
    ans.push(q.top().second);
    q.pop();
    int cnt = 1;
    while(!q.empty()){
        while(!ans.empty() && q.top().first>=ans.top()){
            ans.pop();
        }
        ans.push(q.top().second);
        q.pop();
        cnt=max(cnt, (int)ans.size());
    }
    cout << cnt << "\n";
}