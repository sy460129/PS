#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool check[101];
int gcd(int x, int y){
	return !y ? x : gcd(y, x%y);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x;
	while(1){
		set<int>s;
		cin >> n;
		if(!n) break;
		vector<int>v(n);
		for(int i=0; i<n; i++) cin >> v[i];
		for(int i=1; i<101; i++){
			if(check[i]) continue;
			x=v[0];
			for(int j=0; j<n; j++){
				if(x%i) x=v[j];
				else x=gcd(x, v[j]);
				s.insert(x);
				check[x]=true;
			}
		}
		cout << s.size() << "\n";
		fill(check, check+101, 0);
	}
}