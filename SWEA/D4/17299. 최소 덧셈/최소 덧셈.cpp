#include <iostream>
#include <string>
using namespace std;
int main(){
	string s, c;
	int n, ans; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s;
		if(s.length()%2==0){
			c=s.substr(s.length()/2, s.length()-1);
			s.erase(s.begin()+s.length()/2, s.end());
			cout << "#" << i << " " <<  stoi(s)+stoi(c) << "\n";
		}
		else{
			c=s.substr(s.length()/2, s.length()-1);
			s.erase(s.begin()+s.length()/2, s.end());
			int x=stoi(s)+stoi(c);
			s+=c;
			c=s.substr(s.length()/2+1, s.length()-1);
			s.erase(s.begin()+s.length()/2+1, s.end());
			int y=stoi(s)+stoi(c);
			cout << "#" << i << " ";
			x>y ? cout << y << "\n" : cout << x << "\n";
		}
	}
}