#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[100001];
int n, m, j, cnt, t;
int main(){
     cin >> n >> m;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=n-1; i>=0; i--){
        if(check[i]) continue;
        cnt++;
        check[i]=true;
        t=v[i];
        while(1){
            t+=v[j];
            if(t>m) break;
            check[j]=true;
            j++;
        }
    }
    cout << cnt;
}