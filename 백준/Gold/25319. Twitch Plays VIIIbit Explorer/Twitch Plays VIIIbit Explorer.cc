#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int>>q[26];
int arr[26];
vector<char>v;
int main(){
	bool check=true;
	int n, m, k, c=0, l=0;
	string s;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			q[s[j]-'a'].push({i,j});
		}
	}
	cin >> s;
	for(int i=0; i<s.length(); i++){
		arr[s[i]-'a']++;
	}
	int i=0, j=0;
	k=0;
	while(1){
		if(k==0){
			for(int o=0; o<s.length(); o++)
				if(q[s[o]-'a'].size()<arr[s[o]-'a']){
					check=false;
					break;
				}
			}
		if(!check){
			break;
		}
		int x=q[s[k]-'a'].front().first, y=q[s[k]-'a'].front().second;
		q[s[k]-'a'].pop();
		if(i<x){
			while(i!=x){
				i++, l++;
				v.push_back('D');
			}
		}
		if(i>x){
			while(i!=x){
				i--, l++;
				v.push_back('U');
			}
		}
		if(j<y){
			while(j!=y){
				j++, l++;
				v.push_back('R');
			}
		}
		if(j>y){
			while(j!=y){
				j--, l++;
				v.push_back('L');
			}
		}
		v.push_back('P');
		k++, l++;
		if(k==s.length()) c++, k=0;
	}
	if(i<n-1){
		while(i!=n-1){
			i++, l++;
			v.push_back('D');
		}
	}
	if(j<m-1){
		while(j!=m-1){
			j++, l++;
			v.push_back('R');
		}
	}
	cout << c << " " << l << "\n";
	for(auto e : v){
		cout << e;
	}
}