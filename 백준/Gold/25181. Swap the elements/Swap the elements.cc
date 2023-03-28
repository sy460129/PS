#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[5001];
int brr[5001];
int dp[100001];
bool c;
vector<int>v;
int main(){
	int n, t=0; cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		brr[i]=arr[i];
		dp[arr[i]]++;
		if(dp[arr[i]]>n/2) c=true;
	}
	if(c){
		cout << -1;
		return 0;
	}
	t=arr[0];
	for(int i=0; i<n-1; i++) arr[i]=arr[i+1];
	arr[n-1]=t;
	for(int i=0; i<n; i++){
		if(arr[i]==brr[i]){
			for(int j=0; j<n; j++){
				if(arr[j]!=brr[i] && arr[j]!=arr[i] && arr[i]!=brr[j]) {
					swap(arr[i],arr[j]);
					break;
				}
			}
		}
	}
	for(int i=0; i<n; i++) cout << arr[i] << " ";
}