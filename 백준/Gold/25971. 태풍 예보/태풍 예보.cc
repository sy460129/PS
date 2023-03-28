#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;
using ll=long long;
tuple<ll, ll, ll>v[200002];
bool check[200002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k, r, q, a, b, c, p=1, x, y, z;
    cin >> n >> k >> r >> q;
    for(int i=0; i<k; i++){
        cin >> a >> b >> c;
        v[a]={b,c,0};
        if(a!=1){
            if(b==get<0>(v[p])){
                if(get<1>(v[p])<=c){
                    for(int j=p; j<=a; j++){
                        if(j==p) get<2>(v[p])=1;
                        else v[j]={b,get<1>(v[j-1])+1,1};
                    }
                }
                else{
                    for(int j=p; j<=a; j++){
                        if(j==p) get<2>(v[p])=2;
                        else v[j]={b,get<1>(v[j-1])-1,2};
                    }
                }
            }
            else{
                if(get<0>(v[p])<=b){
                    for(int j=p; j<=a; j++){
                        if(j==p) get<2>(v[p])=3;
                        else v[j]={get<0>(v[j-1])+1,c,3};
                    }
                }
                else{
                    for(int j=p; j<=a; j++){
                        if(j==p) get<2>(v[p])=4;
                        else v[j]={get<0>(v[j-1])-1,c,4};
                    }
                }
                
            }
        }
        p=a;
    }
    while(q--){
        cin >> a >> b >> c;
        x=get<0>(v[a]), y=get<1>(v[a]), z=get<2>(v[a]);
        double d=sqrt((x-b)*(x-b)+(y-c)*(y-c));
        if(r<d) cout <<"gori";
        else{
            if(z==1){
                if(x==b) cout << "gori";
                else if(x<b) cout << "unsafe";
                else cout << "safe";
            }
            else if(z==2){
                if(x==b) cout << "gori";
                else if(x>b) cout << "unsafe";
                else cout << "safe";
            }
            else if(z==3){
                if(y==c) cout << "gori";
                else if(y>c) cout << "unsafe";
                else cout << "safe";
            }
            else{
                if(y==c) cout << "gori";
                else if(y<c) cout << "unsafe";
                else cout << "safe";
            }
        }
        cout << "\n";
    }
}