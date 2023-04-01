#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int res, ans, n, m, h=2147483647;
int arr[21][21];
vector<int>v;
bool check[21];
void dfs(int t){
	if(v.size()==n/2){
		ans=0, res=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(check[i] && check[j]){
					ans+=arr[i][j];
				}
				else if(!check[i] && !check[j]){
					res+=arr[i][j];
				}
			}
		}
		h=min(abs(res-ans), h);
		return;
	}
	for(int i=t; i<n; i++){
		if(!check[i]){
			v.push_back(i);
			check[i]=true;
			dfs(i+1);
			v.pop_back();
			check[i]=false;
		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	dfs(0);
	cout << h;
}