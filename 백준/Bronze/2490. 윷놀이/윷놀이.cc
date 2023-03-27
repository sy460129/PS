#include <iostream>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int r, a;
int main(){
    rep(i, 0, 3){
        rep(j, 0, 4){
            cin >> a;
            r+=a;
        }
        r==3 ? cout << "A" : r==2 ? cout << "B" : r==1 ? cout << "C" : r==0 ? cout << "D" : cout << "E";
        cout << "\n";
        r=0;
    }
}