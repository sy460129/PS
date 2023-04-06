#include <iostream>
#include <vector>
using namespace std;
bool check[200002];
int arr[200002];
int main(){
    int n, x, y, t=-1; cin >> n;
    for(int i=0; i<n; i++){
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
    for(int i=0; i<=t; i++) cout << arr[i] << " ";
}