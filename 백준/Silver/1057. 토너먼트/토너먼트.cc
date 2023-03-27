#include <iostream>
using namespace std;
int main(){
    int n, a, b, cnt=0; cin >> n >> a >> b;
    while(1){
        a=(a+1)/2;
        b=(b+1)/2;
        cnt++;
        if(a==b) break;
    }
    cout << cnt;
}