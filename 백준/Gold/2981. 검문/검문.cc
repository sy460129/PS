#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	vector<int>v;
	int n;
	cin >> n;
	int* arr=new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int d=arr[1]-arr[0];
	for(int i=0; i<n-1; i++){
		d=gcd(d, arr[i+1]-arr[i]);
	}
	v.push_back(d);
	for(int i=2; i<=sqrt(d); i++){
		if(d%i==0){
			v.push_back(i);
			if(i!=d/i) v.push_back(d/i);
		}
	}
	sort(v.begin(), v.end());
	for(auto e : v){
		cout << e << " ";
	}
}