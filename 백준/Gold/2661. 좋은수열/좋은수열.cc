#include <iostream>
#include <string>
using namespace std;
int n;
string s, a, b;
void dfs(){
	if(s.length()==n){
		cout << s;
		exit(0);
	}
	else if(s.length()>n) return;
	for(int i=1; i<=3; i++){
		bool ch=false;
		s+=to_string(i);
		a=s[s.length()-2], b=s[s.length()-1];
		int j=3;
		while(1){
			if(a==b){
				ch=true, s.pop_back();
				break;
			}
			b=a[a.length()-1]+b;
			a.pop_back();
			if(b.length()>(s.length()+1)/2) break;
			while(a.length()!=b.length() && s.length()>=j){
				a=s[s.length()-j]+a;
				j++;
			}				
		}
		if(!ch){
			dfs();
			s.pop_back();
		}
	}
}
int main(){
	cin >> n;
	for(int i=1; i<=3; i++){
		s+=to_string(i);
		dfs();
	}
}