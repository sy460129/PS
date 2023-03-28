#include <iostream>
using namespace std;
int main(){
    int n, t, x, y; cin >> t >> n;
    while(n--){
        cin >> x >> y;
        t-=x*y;
    }
    t ? cout << "No" : cout << "Yes";
}