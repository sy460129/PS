#include <iostream>
#include <map>
#include <set>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
map<string, int>m;
int main(){
	int n, ma=-1, mi=2147483647; cin >> n;
	string s;
	rep(i, 0, n){
		rep(j, 0, 4){
			rep(k, 0, 7){
				cin >> s;
				if(s=="-") continue;
				if(j%4==0 || j%4==2) m[s]+=4;
				else if(j%4==1) m[s]+=6;
				else m[s]+=10;
			}
		}
	}
	for(auto it : m){
		ma=max(ma, it.second);
		mi=min(mi, it.second);
	}
	ma-mi>12 ? cout << "No" : cout << "Yes";
}