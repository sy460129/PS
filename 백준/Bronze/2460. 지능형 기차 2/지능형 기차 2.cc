#include <iostream>
using namespace std;
int arr[5][5];
int res, ans, x, y;
int main(){
    for(int i=0; i<10; i++){
        cin >> x >> y;
        res-=x;
        res+=y;
        ans=max(ans, res);
    }
    cout << ans;
}