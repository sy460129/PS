#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<pair<int,int>>q;
vector<int>v;
bool flag;
int main(){
    int n, m, k; cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> k;
        q.push({k,i});
    }
    while(!q.empty()){
        int x=q.top().first, y=q.top().second; q.pop();
        if(!v.empty() && v.back()==y){
            if(q.empty()){
                flag=true;
                break;
            }
            int i=q.top().first, j=q.top().second; q.pop();
            q.push({x,y});
            if(i!=1) q.push({i-1,j});
            v.push_back(j);
        }
        else{
            v.push_back(y);
            if(x!=1) q.push({x-1, y});
        }
    }
    if(flag) cout << -1;
    else{
        for(auto e : v) cout << e << " ";
    }
}