#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,x;
	cin >> n;
	while(n--){
		string s;
		bool c=true;
		cin >> x;
		if(x==0){
			cout << 0 << "\n";
		}
		else{
			if(x<0){
				c=false;
				x*=-1;
			}
			while(x!=0){
				if(x%3==0){
					s+='0';
				}
				else if(x%3==2){
					s+='-';
					x++;
				}
				else{
					s+='1';
					x--;
				}
				x/=3;
			}
			reverse(s.begin(),s.end());
			if(!c){
				for(int i=0; i<s.length();i++){
					if(s[i]=='1'){
						s[i]='-';
					}
					else if(s[i]=='-'){
						s[i]='1';
					}
				}
			}
			cout << s << "\n";
		}
	}
}