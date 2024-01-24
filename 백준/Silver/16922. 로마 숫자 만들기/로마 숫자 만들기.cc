#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<char>ans;
set<int>s;
char arr[]={'I','V','X','L'};
int n;
void dfs(int t){
	if(ans.size()==n){
		int a=0;
		for(auto e : ans){
			if(e=='I') a++;
			else if(e=='V') a+=5;
			else if(e=='X') a+=10;
			else if(e=='L') a+=50;
		}
		s.insert(a);
		return;
	}
	for(int i=t; i<4; i++){
		ans.push_back(arr[i]);
		dfs(i);
		ans.pop_back();
	}
}
int main(){
	cin >> n;
	dfs(0);
	cout << s.size();
}