#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int>v;
    int m, n, l, x, y, cnt;
    cin >> m >> n >> l;
    while(m--){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    while(n--){
        cin >> x >> y;
        if(y<=l) {
            auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
            if(v[it]-x+y<=l) cnt++;
            else if(it!=v.size()-1 && v[it+1]-x+y<=l) cnt++;
            else if(it!=0 && abs(v[it-1]-x)+y<=l) cnt++;
        }
    }
    cout << cnt;
}