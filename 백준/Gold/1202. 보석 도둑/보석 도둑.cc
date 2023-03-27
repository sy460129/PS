#include <iostream>
#include <queue>
#include <set>
using namespace std;
using p=pair<int,int>;
using ll=long long;
priority_queue<p>q;
multiset<int>s;
ll n, k, x, y, ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    while(n--) {
        cin >> x >> y;
        q.push({y, x});
    }
    while(k--){
        cin >> x;
        s.insert(x);
    }
    while(!q.empty()){
        auto it=s.lower_bound(q.top().second);
        if(it!=s.end()){
            s.erase(it);
            ans+=q.top().first;
        }
        q.pop();
    }
    cout << ans;
}