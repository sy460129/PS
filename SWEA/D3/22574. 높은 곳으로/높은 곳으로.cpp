#include <iostream>
using namespace std;
int main(){
	int t, n, p, sum; cin >> t;
	while(t--){
		cin >> n >> p;
		for(int i=1; i<=n; i++){
			sum+=i;
			if(sum==p) sum--;
		}
		cout << sum << "\n";
		sum=0;
	}
}