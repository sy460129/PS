#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll=long long;
vector<ll>v;
stack<ll>s;
int main(){
	long long x, n, ans=0; cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		if(v.empty() || v.back()!=x) v.push_back(x);
	}
	for(int i=0; i<v.size(); i++){
		if(!s.empty() && s.top()<v[i]){
			ans+=v[i]-s.top();
			while(!s.empty() && s.top()<v[i]) s.pop();
		}
		s.push(v[i]);
	}
	while(s.size()>1){
		x=s.top(); s.pop();
		ans+=s.top()-x;
	}
	cout << ans;
}