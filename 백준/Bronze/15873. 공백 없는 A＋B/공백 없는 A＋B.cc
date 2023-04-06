#include<iostream>
#include <iomanip>
using namespace std;
int main(){
	int t=0;
	string s;
	cin>>s;
	for(int i=0; i<s.length(); i++){
		if(s[i]-'0'==0){
			t-=s[i-1]-'0';
			t+=(s[i-1]-'0')*10;
		}
		else{
			t+=s[i]-'0';
		}
	}
	cout << t;
}