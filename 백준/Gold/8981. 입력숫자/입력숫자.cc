#include <iostream>
using namespace std;
int num[101];
int arr[101];
int main(){
    int i, n, f=0; cin >> n;
    for(i=0; i<n; i++) cin >> num[i];
    cout << n << "\n";
    for(int i=0; i<n; i++){
        while(arr[f]){ 
            f=(f+1)%n;
        }
        arr[f]=num[i];
        f=(arr[f]+f)%n;
    }
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}