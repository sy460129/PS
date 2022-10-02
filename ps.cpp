#include <iostream>
using namespace std;
char arr[201];
void preOrder(int i){
    cout << arr[i];
    preOrder(arr[i*2]);
    preOrder(arr[i*2+1]);
}
void prOrder(int i){
    preOrder(arr[i*2]);
    cout << arr[i];
    preOrder(arr[i*2+1]);
}
void pOrder(int i){
    preOrder(arr[i*2]);
    preOrder(arr[i*2+1]);
    cout << arr[i];
}
int main(){
    int n;
    char x, y, z;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> y >> z;
        arr[i]=x-'A';
        if(y!='.') arr[i*2]=y-'A';
        if(z!='.') arr[i*2+1]=z-'A';
    }
    preOrder(arr[1]);
    prOrder(arr[1]);
    pOrder(arr[1]);
}