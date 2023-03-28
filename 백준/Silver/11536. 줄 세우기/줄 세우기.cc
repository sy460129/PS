#include <iostream>
#include <algorithm>
using namespace std;
string arr[21];
string brr[21];
bool c;
int main() {
	int n, i=0;
	string s;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		arr[i]=s;
		brr[i]=s;
	}
	sort(brr, brr+n);
	c=true;
	for(int i=0; i<n; i++){
		if(arr[i]!=brr[i]){
			c=false;
			break;
		}
	}
	if(c){
		cout << "INCREASING";
		return 0;
	}
	c=true;
	for(int i=0; i<n; i++){
		if(arr[i]!=brr[n-i-1]){
			c=false;
			break;
		}
	}
	if(c){
		cout << "DECREASING";
		return 0;
	}
	else{
		cout << "NEITHER";
	}
}