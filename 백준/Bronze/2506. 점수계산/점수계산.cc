#include <iostream>
using namespace std;
int n, x, res, t;
int main(){
    cin >> n;
    while(n--){
        cin >> x;
        x==1 ? t++ : t=0;
        res+=t;
    }
    cout << res;
}