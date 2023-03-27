#include <iostream>
using namespace std;
int main(){
	int n, t=1, ans=1;
	cin >> n;
	int* arr=new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<n-1; i++){
		if(arr[i]<=arr[i+1]){
			t++;
		}
		else{
			ans=max(ans,t);
			t=1;
		}
	}
	t=1;
	for(int i=0; i<n-1; i++){
		if(arr[i]>=arr[i+1]){
			t++;
		}
		else{
			ans=max(t,ans);
			t=1;
		}
	}
	ans=max(t,ans);
	cout << ans;
}