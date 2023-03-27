#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double x, y, d, t, ans=2147483647, res, p=0;
    int i=1;
    cin >> x >> y >> d >> t;
    res=sqrt(x * x + y * y);
    p=d;
    while(1){
        if(abs(p-res)>=ans){
            p-=d, i--;
            break;
        }
        ans=abs(p-res);
        p+=d;
        i++;
    }
    ans=res;
    if(p>=res){
        if(i==1) ans=min(ans,min(t*2, t+p-res));
        else ans=min(i*t, ans);
    }
    if(p<res) ans=min(ans, min(i*t+res-p, t*(i+1)));
    cout << fixed << setprecision(11) << ans;
}