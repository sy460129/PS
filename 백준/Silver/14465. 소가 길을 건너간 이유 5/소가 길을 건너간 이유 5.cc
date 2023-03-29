#include <iostream>
using namespace std;
int a[100001];
int main(){
	int n,k,b,x,m=210232,res=0;
	cin >> n >> k >> b;
	while(b--){
		cin >> x;
		a[x]++;
	}
	int s=1,e=1;
	while(e<=n){
		if(e-s<k){
			if(a[e]==1){
				res++;
			}
			e++;
		}
		else if(e-s==k){
			if(a[s]==1){
				res--;
			}
			s++;
			m=min(res,m);
		}
	}
	cout << m;
}