#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string>v, ans;
string m;
bool use, z;
bool cmp(string a, string b){
	if(a.length()>m.length()) m=a;
	else if(a.length()==m.length()) m=max(a,m);
	if(b.length()>m.length()) m=b;
	else if(b.length()==m.length()) m=max(b,m);
	return a+b>b+a;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string tmp, x;
	for(int i=0; i<n; i++){
		cin >> x;
		reverse(x.begin(), x.end());
		for(int j=0; j<x.length(); j++){
			if(x[j]=='6') x[j]='9';
			else if(x[j]=='9') x[j]='6';
			if(x[j]!='0') z=true;
		}
		v.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	if(v.size()==1) m=v[0];
	reverse(m.begin(), m.end());
	for(int j=0; j<m.length(); j++){
		if(m[j]=='6') m[j]='9';
		else if(m[j]=='9') m[j]='6';
	}
	for(int i=0; i<n; i++){
		reverse(v[i].begin(), v[i].end());
		for(int j=0; j<v[i].length(); j++){
			if(v[i][j]=='6') v[i][j]='9';
			else if(v[i][j]=='9') v[i][j]='6';
		}
		if(v[i]==m && !use){
			use=true;
			ans.push_back(v[i]);
		}
		ans.push_back(v[i]);
	}
	if(!z) cout << 0;
	else for(int i=ans.size()-1; i>=0; i--) cout << ans[i];
}