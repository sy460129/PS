#include <iostream>
#include <vector>
using namespace std;
vector<char>v;
bool check;
int main(){
	string s, c="PPAP";
	cin >> s;
	if(s.length()==1 && s=="A"){
		cout << "NP";
		return 0;
	}
	for(int i=0; i<s.length(); i++){
		v.push_back(s[i]);
		check=true;
		if(v.back()=='P' && v.size()>3){
			for(int j=0; j<4; j++){
				if(v[v.size()-j-1]!=c[c.length()-1-j]){
					check=false;
				}
			}
			if(check){
				for(int j=0; j<3; j++){
					v.pop_back();
				}
			}
		}
	}
	if(v.size()==1){
		cout << "PPAP";
	}
	else{
		cout << "NP";
	}
}