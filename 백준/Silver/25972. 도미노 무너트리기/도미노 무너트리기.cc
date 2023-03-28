#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>>v;
int main(){
    int n, x, y, l=0, ans=0; cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(l<v[i].first){
            ans++;
        }
        l=v[i].first+v[i].second;
    }
    cout << ans;
}