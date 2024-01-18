#include <iostream>
#include <set>
using namespace std;
multiset<int>s;
int main(){
	int n, x, base, cnt; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x;
		if(i==1) base=x;
		else{
			cnt=0;
			for(auto it=s.begin(); it!=s.end(); it++) cnt+=i%(*it);
			cnt+=base*i;
			cnt-=x;
			cnt/=i;
			while(cnt--){
				s.insert(i);
				base--;
			}
		}
	}
	cout << s.size() << " ";
	for(auto e : s) cout << e << " ";
}