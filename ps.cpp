#include <iostream>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    set<int>s;
    int m, n, l, x, y, cnt=0;
    cin >> m >> n >> l;
    while(m--){
        cin >> x;
        s.insert(x);
    }
    while(n--){
        cin >> x >> y;
        if(y<=l) {
            auto it=s.lower_bound(x);
            if(abs((*it)-x)+y<=l || (it!=s.begin() && abs(x-(*(--it)))+y<=l)) cnt++;
        }
    }
    cout << cnt;
}