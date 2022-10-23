#include <iostream>
using namespace std;
int n, cnt;
int col[16];
bool check(int t, int j){
    for(int i=1; i<t;i++){
        if(col[i]==j || abs(j-col[i])==abs(i-t)) return false;
    }
    return true;
}
void nqueen(int x){
    if(x==n+1){
        cnt++;
        return;
    }
    for(int i=1; i<=n; i++){
        if(check(x, i)){
            col[x]=i;
            nqueen(x+1);
        }
    }
    col[x]=0;
}
int main(){
    cin >> n;
    nqueen(1);
    cout << cnt;
}