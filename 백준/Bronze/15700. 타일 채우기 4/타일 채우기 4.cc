#include <iostream>
using namespace std;
int main(){
	long long n, m, ans=0; cin >> n >> m;
	ans+=n*(m/2);
	if(m%2) ans+=n/2;
	cout << ans;
}