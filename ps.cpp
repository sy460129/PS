#include <iostream>
using namespace std;
int arr[100001];
int ask(int a){
	int x;
	cout << "? " << a << "\n";
	cin >> x;
	arr[a]=x;
	return x;
}
int main(){
	int n; cin >> n;
	int f=1, e=n;
	arr[0]=n+1, arr[n+1]=n+1;
	while(f<e){
		int m=(f+e)/2;
		ask(m);
		ask(m+1);
		if(arr[m]<arr[m+1]){
			e=m;
		}
		else f=m+1;
	}
	cout << "! " << e;
	cout.flush();
}