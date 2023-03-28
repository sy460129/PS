#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n, x;
	cin >> n;
	while(n--){
		int t=0;
		cin >> x;
		for(int i=2; i<=sqrt(x); i++){
			if(x%i==0){
				t+=i;
				if(i*i!=x){
					t+=x/i;
				}
			}
		}
		t++;
		if(t==x){
			cout << x << " is a perfect number.\n\n";
		}
		else if(t<x){
			cout << x << " is a deficient number.\n\n";
		}
		else{
			cout << x << " is an abundant number.\n\n";
		}
	}
}