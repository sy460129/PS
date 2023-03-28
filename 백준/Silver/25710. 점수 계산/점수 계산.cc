#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001];
int main(){
    vector<int>v;
    int n, x, t, cnt, ans=-1; cin >> n;
    while(n--){
        cin >> x;
        arr[x]++;
    }
    for(int i=0; i<1000; i++){
        if(arr[i]!=0){
            v.push_back(i);
            if(arr[i]!=1) v.push_back(i);
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            t=v[i]*v[j];
            cnt=0;
            while(t!=0){
                cnt+=t%10;
                t/=10;
            }
            ans=max(ans, cnt);
        }
    }
    cout << ans;
}