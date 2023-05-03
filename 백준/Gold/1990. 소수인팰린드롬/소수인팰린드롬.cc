#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int a, b; cin >> a >> b;
	string s;
	if(!(a%2)) a++;
	for(int i=a; i<=b; i+=2){
		s=to_string(i);
		bool c=true;
		for(int j=0; j<s.length()/2; j++){
			if(s[j]!=s[s.length()-j-1]){
				c=false;
				break;
			}
		}
		if(c){
			for(int j=2; j<=sqrt(i); j++){
				if(!(i%j)){
					c=false;
					break;
				}
			}
			if(c) cout << i << "\n";
		}
	}
	cout << -1;
}