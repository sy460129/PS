#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
queue<string>q;
map<string, int>m;
int main(){
	string s, c; cin >> s >> c;
	q.push(c);
	while(!q.empty()){
		string x=q.front(); q.pop();
		if(x[0]==x[x.length()-1]){
			if(x[0]=='B'){
				reverse(x.begin(), x.end());
				x.pop_back();
				if(x==s){
					cout << 1;
					return 0;
				}
				if(x.length()>s.length() && !m.count(x)) q.push(x), m[x]++;
			}
			else{
				x.pop_back();
				if(x==s){
					cout << 1;
					return 0;
				}
				if(x.length()>s.length() && !m.count(x)) q.push(x), m[x]++;
			}
		}
		else{
			if(x[0]=='B'){
				string t=x;
				reverse(t.begin(), t.end());
				t.pop_back();
				if(t==s){
					cout << 1;
					return 0;
				}
				if(t.length()>s.length() && !m.count(t)) q.push(t), m[t]++;
				x.pop_back();
				if(x==s){
					cout << 1;
					return 0;
				}
				if(x.length()>s.length() && !m.count(x)) q.push(x), m[x]++;
			}
		}
	}
	cout << 0;
}