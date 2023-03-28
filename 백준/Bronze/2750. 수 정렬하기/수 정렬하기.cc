#include<iostream>
#include<algorithm>
using namespace std;
int compare(int a, int b){
    return a<b;
}
int main() {
    int n;
    cin >> n;
    int *p=new int[n];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p,p+n,compare);
    for(int i=0; i<n; i++){
        cout << p[i] << "\n";
    }
}