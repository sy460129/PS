#include<iostream>
using namespace std;
int main(){
	int n, a=0; cin >> n;
	for(int i=1; i<=n; i++) if(n%i==0) a+=i;
	cout << a*5-24;
}