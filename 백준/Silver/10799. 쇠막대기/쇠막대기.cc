#include<iostream>
using namespace std;
int main() {
	int ans=0, t=0;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='(') t++;
		else{
			if(s[i-1]=='(') ans+=t-1, t--;
			else t--, ans++;
		}
	}
	cout << ans;
}