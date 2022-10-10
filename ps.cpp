#include <iostream>
#include <vector>
using namespace std;
int t, n, k, cnt;
string s;
vector<int>v;
bool check, c;
void dfs(int n){
	if(n==v.size()){
		for(int i=0; i<s.length(); i++){
			if(s[i]=='1') cnt++;
			else {
				if(cnt==k){
					if(!check) check=true;
					else {
						c=true;
					}
				} 
				cnt=0;
			}
		}
	}
	for(int i=n+1; i<v.size(); i++){
		s[v[i]]='1';
		dfs(n+1);
		s[v[i]]='0';
	}
}
int main(){
	cin >> t;
	while(t--){
		v.clear();
		check=false, c=false;
		cnt=0;
		cin >> n >> k >> s;
		for(int i=0; i<s.length(); i++){
			if(s[i]=='?') v.push_back(i);
		}
		dfs(0);
		if(c || !check) cout << "No\n";
		else cout << "Yes\n";
	}
}