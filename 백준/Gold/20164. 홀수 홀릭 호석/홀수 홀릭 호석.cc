#include <iostream>
#include <string>
using namespace std;
int mi=2147483647, ma;
void back(string s, int ans){
	string a, b, c;
	if(s.length()==1){
		if((s[0]-'0')%2) ans++;
		mi=min(mi, ans);
		ma=max(ma, ans);
		return;
	}
	else if(s.length()==2){
		if((s[0]-'0')%2) ans++;
		if((s[1]-'0')%2) ans++;
		s=to_string(s[0]-'0'+s[1]-'0');
		back(s, ans);
	}
	else{
		int cnt=stoi(s);
		while(cnt!=0){
			if(cnt%2) ans++;
			cnt/=10;
		}
		for(int i=1; i<s.length()-1; i++){
			for(int j=1; j<s.length()-i; j++){
				a=s.substr(0,i);
				b=s.substr(i,j);
				c=s.substr(i+j,s.length());
				cnt=stoi(a)+stoi(b)+stoi(c);
				back(to_string(cnt), ans);
			}
		}
	}
}
int main(){
	string s; cin >> s;
	back(s, 0);
	cout << mi << " " << ma;
}