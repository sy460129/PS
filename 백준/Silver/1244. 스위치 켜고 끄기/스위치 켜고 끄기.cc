#include <iostream>
using namespace std;
int arr[101];
int main(){
	int n, x, a, b;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	cin >> x;
	while(x--){
		cin >> a >> b;
		if(a==1){
			int t=b;
			while(t<=n){
				arr[t]++;
				t+=b;
			}
		}
		else{
			int t=1;
			arr[b]+=1;
			while(b-t>0 && b+t<=n && arr[b-t]%2==arr[b+t]%2){
				arr[b-t]++;
				arr[b+t]++;
				t++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		cout << arr[i]%2 << " ";
		if(i%20==0){
			cout << "\n";
		}
	}
}