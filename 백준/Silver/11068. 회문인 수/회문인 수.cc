#include <iostream>
#include <string>
using namespace std;
int main() {
	int t, n, b, x; cin >> t;
	while(t--){
		bool c;
		cin >> n;
		for(int i=2; i<=64; i++){
			c=true;
			x=n;
			string s;
			while(x!=0){
				b=x%i;
				x/=i;
				s+=(char)(b+33);
			}
			for(int j=0; j<s.length()/2; j++){
				if(s[j]!=s[s.length()-1-j]){
					c=false;
					break;
				}
			}
			if(c) break;
		}
		c ? cout << "1\n" : cout << "0\n";
	}
}