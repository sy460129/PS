#include <iostream>
#include <vector>
#include <queue>
#define MAX 2147483648
using namespace std;
using ll=long long;
using p=pair<ll,ll>;
vector<p>v;
priority_queue<p>q;
int main(){
    ll n, m, x, y, p, w=0, ans=MAX;
    cin >> n >> m;
    while(n--){
        cin >> x >> y;
        q.push({y,x});
        w+=x;
    }
    while(!q.empty() && w>=m){
        x=q.top().first, y=q.top().second; q.pop();
        p=x;
        while(!q.empty() && q.top().first==x){
            p+=q.top().first;
            v.push_back({q.top().first, q.top().second});
            q.pop();
        }
        while(!v.empty() && w>=m){
            ans=min((ll)p, ans);
            p-=v.back().first;
            w-=v.back().second;
            v.pop_back();
        }
        if(w<m) break;
        ans=min((ll)p, ans);
        w-=y;
        v.clear();
    }
    ans==MAX ? cout << -1 : cout << ans;
}