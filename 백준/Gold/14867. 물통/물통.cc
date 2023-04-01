#include <iostream>
#include <queue>
#include <set>
using namespace std;
queue<pair<int,int>>q, q2;
int a, b, c, d, t, cnt;
set<pair<int,int>>s;
void bfs(){
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        if(x==c && y==d){
            cout << cnt;
            exit(0);
        }
        q.pop();
        t=s.size();
        s.insert({x,0});
        if(s.size()>t) q2.push({x,0}), t++;
        s.insert({x,b});
        if(s.size()>t) q2.push({x,b}), t++;
        if(a-x>=y){
            s.insert({x+y,0});
            if(s.size()>t) q2.push({x+y,0}), t++;
        }
        else {
            s.insert({a,y-(a-x)});
            if(s.size()>t) q2.push({a,y-(a-x)}), t++;
        }
        s.insert({0,y});
        if(s.size()>t) q2.push({0,y}), t++;
        if(b-y>=x){
            s.insert({0,x+y});
            if(s.size()>t) q2.push({0,x+y}), t++;
        }
        else {
            s.insert({x-(b-y),b});
            if(s.size()>t) q2.push({x-(b-y),b}), t++;
        }
        s.insert({a,y});
        if(s.size()>t) q2.push({a,y}), t++;
        if(q.empty()){
            q=q2;
            while(!q2.empty()) q2.pop();
            cnt++;
        }
    }
}
int main(){
    cin >> a >> b >> c >> d;
    q.push({0,0});
    s.insert({0,0});
    t=1;
    bfs();
    cout << -1;
}