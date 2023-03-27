#include <iostream>
using namespace std;
using ull=unsigned long long;
ull gcd(ull x, ull y){
    return y ? gcd(y, x%y) : x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ull a, b; cin >> a >> b;
    ull t=gcd(a, b);
    for(ull i=0; i<t; i++){
        cout << 1;
    }
}