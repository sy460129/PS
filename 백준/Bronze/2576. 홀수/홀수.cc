#include <iostream>
using namespace std;
int main(){
    int n, r=101, a=0;
    for(int i=0; i<7; i++){
        cin >> n;
        if(n%2!=0) r=min(r, n), a+=n;
    }
    a!=0 ? cout << a << "\n" << r : cout << -1;
}