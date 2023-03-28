#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool c, ch;
int main(){
	vector<int>v;
	string s; cin >> s;
	reverse(s.begin(), s.end());
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='1'){
			if(c && !ch){
				if(v.size()==2) v.clear(), c=false;
				else break;
			}
			v.push_back('1');
			if(ch) v.clear(), c=false, ch=false;
		}
		else{
			if(v.empty()) {
				v.push_back('0');
				break;
			}
			v.push_back('0');
			if(!c) c=true;
			else if(!ch) ch=true;
		}
	}
	if(v.size()==2 && v[0]=='1' && v[1]=='0') v.clear();
	!v.empty() ? cout << "NOISE" : cout << "SUBMARINE";
}