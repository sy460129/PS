#include <iostream>
using namespace std;
int arr[65][65];
int n;
void divide(int x, int y, int t){
    int b=0, w=0;
    for(int i=x; i<x+t; i++){
        for(int j=y; j<y+t; j++){
            arr[i][j]==1 ? b++ : w++;
        }
        if(b!=0 && w!=0) break;
    }
    if(b!=0 && w!=0){
        cout << "(";
        divide(x, y, t/2);
        divide(x, y+t/2, t/2);
        divide(x+t/2, y, t/2);
        divide(x+t/2, y+t/2, t/2);
        cout << ")";
    }
    else b ? cout << 1 : cout << 0;
}
int main(){
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            arr[i][j]=s[j]-'0';
        }
    }
    divide(0, 0, n);
}