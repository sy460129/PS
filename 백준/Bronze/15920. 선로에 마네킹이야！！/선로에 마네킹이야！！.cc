#include <iostream>
using namespace std;
int main(){
	int n, w=0, p=0, res=0;
	string s;
	cin >> n >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='W'){
			w++;
			if(w==2){
				break;
			}
		}
		else {
			if(w==0){
				p++;
			}
			else if(w==1){
				res=6;
			}
		}
	}
	if(w==0 || w==1){
		res=0;
	}
	else {
		if(res!=6){
			if(p%2!=0){
				res=1;
			}
			else{
				res=5;
			}
		}
	}
	cout << res;
}