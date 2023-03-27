#include <iostream>
#include <vector>
using namespace std;
int n;
vector<char>v;
vector<int>vu, vd;
bool c[10], check;
void dfs(int t){
	if(t==n){
		check=true;
		for(auto e : vu) cout << e;
		cout << "\n";
		return;
	}
	for(int i=9; i>=0; i--){
		if(check) return;
		if(vu.empty()){
			vu.push_back(i);
			c[i]=true;
			dfs(0);
			c[i]=false;
			vu.pop_back();
		}
		else{
			if(!c[i]){
				if(v[t]=='<'){
					if(vu.back()<i){
						c[i]=true;
						vu.push_back(i);
						dfs(t+1);
						if(check) return;
						c[i]=false;
						vu.pop_back();
					}
					else return;
				}
				else{
					if(vu.back()>i){
						c[i]=true;
						vu.push_back(i);
						dfs(t+1);
						if(check) return;
						c[i]=false;
						vu.pop_back();
					}
					else return;
				}
			}
		}
	}
}
void dfs2(int t){
	if(t==n){
		check=true;
		for(auto e : vd) cout << e;
		cout << "\n";
		exit(0);
	}
	for(int i=0; i<=9; i++){
		if(check) return;
		if(vd.empty()){
			vd.push_back(i);
			c[i]=true;
			dfs2(0);
			c[i]=false;
			vd.pop_back();
		}
		else{
			if(!c[i]){
				if(v[t]=='<'){
					if(vd.back()<i){
						c[i]=true;
						vd.push_back(i);
						dfs2(t+1);
						if(check) return;
						c[i]=false;
						vd.pop_back();
					}
					else return;
				}
				else{
					if(vd.back()>i){
						c[i]=true;
						vd.push_back(i);
						dfs2(t+1);
						if(check) return;
						c[i]=false;
						vd.pop_back();
					}
					else return;
				}
			}
		}
	}
}
int main(){
	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++) cin >> v[i];
	dfs(0);
	check=false;
	fill(c, c+10, 0);
	dfs2(0);
}