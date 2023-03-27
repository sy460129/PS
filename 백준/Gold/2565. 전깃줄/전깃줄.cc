#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
vector<pair<int,int>>v;
vector<int>v2, vec;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y; cin >> n;
    rep(i, 0, n){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for(auto e : v){
        v2.push_back(e.second);
    }
    vec.push_back(-1);
    rep(i, 0, v2.size()){
        if(v2[i]>vec.back()) vec.push_back(v2[i]);
        else{
            auto it=lower_bound(vec.begin(), vec.end(), v2[i])-vec.begin();
            vec[it]=v2[i];
        }
    }
    cout << n - vec.size()+1;
}