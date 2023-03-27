#include <iostream>
using namespace std;
int arr[7];
int main() {
    int n, x, ans=0; cin >> n;
    while(n--){
        for(int i=0; i<3; i++){
            cin >> x;
            arr[x]++;
        }
        for(int i=1; i<7; i++) {
            if(arr[i]==3) ans=max(ans, 10000+1000*i);
            else if(arr[i]==2) ans=max(ans, 1000+i*100);
            else if(arr[i]) ans=max(ans, i*100);
            arr[i]=0;
        }
    }
    cout << ans;
}