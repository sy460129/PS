#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>v;
int main(){
    int n, m, t, x, y, ans=0; cin >> n >> m >> t;
    for(int i=0; i<t; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    cin >> x >> y;
    for(int i=0; i<t; i++){
        int a=v[i].first, b=v[i].second;
        if(a==x) ans+=abs(b-y);
        else if(x+a==3){
            ans+=m;
            ans+=min(y+b, 2*n-y-b);
        }
        else if(x+a==7){
            ans+=n;
            ans+=min(y+b, 2*m-y-b);
        }
        else{
            if(x==1) ans+=(y+b);
            else if(x==2){
                if(a==3) ans+=(y+m-b);
                else ans+=(n-y+m-b);
            }
            else{
                if(x==3){
                    if(a==1) ans+=(y+b);
                    else ans+=(m-y+b);
                }
                else if(x==4){
                    if(a==1) ans+=(y+n-b);
                    else ans+=(m-y+n-b);
                }
            }
        }
    }
    cout << ans;
}