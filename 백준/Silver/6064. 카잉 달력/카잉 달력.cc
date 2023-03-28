#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int lcm(int a, int b){
    return (a*b)/(gcd(a, b));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y, t, a, b;
    cin >> t;
    while(t--){
        int res=-1;
        cin >> x >> y >> a >> b;
        a--, b--;
        for(int i=a; i<=lcm(x, y); i+=x){
            if(i%x==a && i%y==b){
                res=i+1;
                break;
            }
        }
        cout << res << "\n";
    }
}