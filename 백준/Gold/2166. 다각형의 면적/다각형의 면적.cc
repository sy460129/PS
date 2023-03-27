#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
ll x[10001];
ll y[10001];
int main(){
	int n;
	ll ans=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=0; i<n-1; i++){
		ans+=x[i]*y[i+1];
	}
	ans+=x[n-1]*y[0];
	for(int i=0; i<n-1; i++){
		ans-=x[i+1]*y[i];
	}
	ans-=x[0]*y[n-1];
	if(ans<0){
		ans*=-1;
	}
	cout << fixed << setprecision(1) << round((double)(ans*10)/2)/10;
}