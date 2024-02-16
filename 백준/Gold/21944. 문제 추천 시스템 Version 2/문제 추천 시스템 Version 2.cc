#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
using pi=pair<int,int>;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t, p, l, g, x; cin >> n;
	set<pi>s, s2[101];
	map<int,pi>m;
	while(n--){
		cin >> p >> l >> g;
		s.insert({l,p}); // {난이도, 번호}
		s2[g].insert({l,p}); // [알고리즘] {난이도, 번호}
		m[p]={l,g}; // [번호] {난이도, 알고리즘}
	}
	string c;
	cin >> t;
	while(t--){
		cin >> c;
		if(c=="add"){
			cin >> p >> l >> g;
			s.insert({l,p});
			s2[g].insert({l,p});
			m[p]={l,g};
		}
		else if(c=="solved"){
			cin >> p;
			s.erase({m[p].first,p});
			s2[m[p].second].erase({m[p].first,p});
			m.erase(p);
		}
		else if(c=="recommend"){
			cin >> g >> x;
			if(x==1){
				auto it=s2[g].end();
				cout << (--it)->second << "\n";
			}
			else{
				auto it=s2[g].begin();
				cout << it->second << "\n";
			}
		}
		else if(c=="recommend2"){
			cin >> x;
			if(x==1){
				auto it=s.end();
				cout << (--it)->second << "\n";
			}
			else{
				auto it=s.begin();
				cout << it->second << "\n";
			}
		}
		else{
			cin >> x >> l;
			if(x==1){
				auto it=s.lower_bound({l,0});
				it==s.end() ? cout << "-1\n" : cout << it->second << "\n";
			}
			else{
				auto it=s.upper_bound({l,0});
				it==s.begin() ? cout << "-1\n" : cout << (--it)->second << "\n";
			}
		}
	}
}