#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
bool check[200002];
int arr[200002];
int main(){
    int n, x, y, t=-1; cin >> n;
    rep(i, 0, n){
        cin >> x;
        if(!check[x]){
            check[x]=true;
            if(i!=0){
                arr[x]=y;
            }
            else arr[x]=-1;
            t=max(t, x);
        }
        y=x;
    }
    cout << t+1 << "\n";
    rep(i, 0, t+1) cout << arr[i] << " ";
}