#include <iostream>
using namespace std;
bool a[26];
bool b[26];
int main() {
	int t, res=0;
	string s;
	cin >> s;
	for(int i=0; i<s.length()-1; i++){
		t=i;
		if(!a[s[i]-'A']){
			a[s[i]-'A']=true;
			while(1){
				t++;
				if(s[i]==s[t]){
					break;
				}
				else{
					if(!b[s[t]-'A']){
						b[s[t]-'A']=true;
					}
					else{
						b[s[t]-'A']=false;
					}
				}
			}
			for(int j=0; j<26; j++){
				if(b[j]){
					res++;
					b[j]=false;
				}
			}
		}
	}
	cout << res/2;
}