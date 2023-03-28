#include <iostream>
using namespace std;
using ll=long long;
pair<ll,ll>check;
int main(){
    ll n, a, pa, b, pb, x, y, ans=0;
    cin >> n >> a >> pa >> b >> pb;
    x=n/pa;
    while(x>=0){
        y=(n-x*pa)/pb;
        while(pa*x+y*pb<=n){
            if(x*a+y*b>ans){
                ans=x*a+y*b;
                check={x,y};
            }
            y++;
        }
        x--;
    }
    cout << check.first << " " << check.second;
}