#include <iostream>
using namespace std;
int arr[1000001];
int main() {
	int n;
	cin >> n;
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	arr[3]=3;
	for(int i=4; i<=n; i++){
		arr[i]=(arr[i-1]+arr[i-2])%15746;
	}
	cout << arr[n];
}