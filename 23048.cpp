#include <iostream>
#include <cmath>
using namespace std;
int arr[500001];
bool check[500001];
int main() {
	int n, t;
	cin >> n;
	t=n;
	for(int i=2; i<=sqrt(n); i++){
		if(arr[i]==0){
			t++;
			for(int j=1; j<=n/i; j++){
				if(arr[i*j]==0){
					arr[i*j]=i;
					t--;
				}
			}
		}
	}
	if(n==2){
		cout << 2 << "\n" << 1 << " " << 2;
		return 0;
	}
	else if(n==3) {
		cout << 3 << "\n" << 1 << " " << 2 << " " << 3;
		return 0;
	}
	int cnt = 1;
	cout << t << "\n";
	for(int i=1; i<=n; i++){
		if(arr[i]==0){
			cout << cnt << " ";
			check[cnt]=true;
		}
		else{
			cout << arr[i] << " ";
			check[arr[i]]=true;
			while(1){
				if(!check[cnt]){
					break;
				}
				cnt++;				
			}
		}
	}
}