#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[5], ans=0;
    for(int i=0; i<5; i++) cin >> arr[i], ans+=arr[i];
    sort(arr, arr+5);
    cout << ans/5 << "\n" << arr[2];
}