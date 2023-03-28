#include <iostream>
using namespace std;
long long n, d, k, s, h;
int main(){
	string c;
	cin >> n >> c;
	for(int i=0; i<n; i++){
		if(c[i]=='D') d++;
		else if(c[i]=='K') k+=d;
		else if(c[i]=='S') s+=k;
		else if(c[i]=='H') h+=s;
	}
	cout << h;
}