#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
using p=pair<int,int>;
int arr[100001];
vector<p>vec, v2, v3;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b; cin >> n >> m;
    rep(i, 0, m) cin >> arr[i];
    rep(i, 0, m){
        rep(j, 0, arr[i]/2){
            cin >> a >> b;
            if(i == 0) v2.push_back({a,b});
            else{
                rep(k, 0, vec.size()){
                    if (vec[k].first<=a){
                        if(a<=vec[k].second){
                            if(v2.empty()) v2.push_back({a,b});
                            else{
                                if(v2.back().first==a && v2.back().second==b) continue;
                                else v2.push_back({a,b});
                            }
                        }
                    }
                    else {
                        if(b>=vec[k].first){
                            if(v2.empty()) v2.push_back({a,b});
                            else{
                                if(v2.back().first==a && v2.back().second==b) continue;
                                else v2.push_back({a,b});
                            }
                        }
                        
                    }
                }
            }
        }
        vec=v2, v2=v3;
    }
    !vec.empty() ? cout << "YES" : cout << "NO";
}