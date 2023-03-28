#include <iostream>
using namespace std;
using ll=long long;
ll k[101], d[101], a[101], ans;
int main(){
    ll n, m, x, y, z;
    cin >> n;
    while(n--){
        ans=0;
        cin >> m;
        for(int i=0; i<m; i++) cin >> k[i] >> d[i] >> a[i];
        cin >> x >> y >> z;
        for(int i=0; i<m; i++){
            if(k[i]*x-d[i]*y+a[i]*z>0) ans+=(k[i]*x-d[i]*y+a[i]*z);
        }
        cout << ans << "\n";
    }
}