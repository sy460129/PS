#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int t, n; cin >> t;
	while(t--){
		vector<int>v;
		cin >> n;
		int x=1;
		bool c=false;
		for(int i=2; i<=sqrt(n); i++){
			if(n%i==0){
				x+=i;
				v.push_back(i);
				if(n/i!=i){
					x+=n/i;
					v.push_back(n/i);
				}
			}
		}
		if(x>n){
			for(auto e : v){
				x=1;
				for(int i=2; i<=sqrt(e); i++){
					if(e%i==0){
						x+=i;
						if(e/i!=i) x+=e/i;
					}
				}
				if(x>e){
					c=true;
					break;
				}
			}
			if(c) cout << "BOJ 2022\n";
			else cout << "Good Bye\n";
		}
		else cout << "BOJ 2022\n";
	}
}