#include <iostream>
using namespace std;
bool dp[100001];
long long gcd(int x, int y){
	return !y ? x : gcd(y, x%y);
}
int main(){
	int n; cin >> n;
	long long x;
	while(n--){
		cin >> x;
		if(x%2) cout << x*(x-1)*(x-2) << "\n";
		else{
			if(x%3) cout << x*(x-1)*(x-3) << "\n";
			else cout << (x-1)*(x-2)*(x-3) << "\n";
		}
	}
}