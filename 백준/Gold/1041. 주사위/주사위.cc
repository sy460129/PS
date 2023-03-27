#include <iostream>
#include <algorithm>
using namespace std;
long long arr[7];
int main(){
	long long n, a=0, t=51, p=101, k=151;
	cin >> n;
	for(int i=0; i<6; i++){
		cin >> arr[i];
        t=min(t, arr[i]);
	}
    k=min(arr[0]+arr[1]+arr[2], min(arr[0]+arr[1]+arr[3], min(arr[0]+arr[2]+arr[4], min(arr[0]+arr[3]+arr[4], min(arr[1]+arr[2]+arr[5], min(arr[1]+arr[3]+arr[5], min(arr[2]+arr[4]+arr[5], min(arr[3]+arr[4]+arr[5], k))))))));
	for(int i=0; i<5; i++){
        for(int j=i+1; j<6; j++){
            if(i==0 && j==5) continue;
            else if(i==1 && j==4) continue;
            else if(i==2 && j==3) continue;
            else p=min(p, arr[i]+arr[j]);
        }
    }
    if(n==1){
        sort(arr, arr+6);
		for(int i=0; i<5; i++){
			a+=arr[i];
		}
		cout << a;
		return 0;
	}
	cout << t*5 *(n-2)*(n-2)+(n-2)*4*t+p*(n-1)*4+ 4*(n-2)*p+k*4;
}