#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	bool check = true;
	int n;
	string s;
	cin >> n;
	if(n<0) {
		check=false;
		n*=-1;
	}
	else if(n==0) {
		cout << 0 << "\n";
		return 0;
	}
	while(n!=0) {
		if(n%3==0) {
			s+='0';
		}
		else if(n%3==2){
			s+='T';
			n+=1;
		}
		else {
			s+='1';
			n-=1;
		}
		n/=3;
	}
	reverse(s.begin(), s.end());
	if(!check){
		for(int i=0; i<s.length(); i++) {
			if(s[i]=='1') {
				s[i]='T';
			}
			else if(s[i]=='T'){
				s[i]='1';
			}
		}
	}
	cout << s;
}