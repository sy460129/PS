#include <iostream>
using namespace std;
using ll=long long;
ll arr[100002];
bool check;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, k, a, x, p, sum=0, c, mi=0;
	cin >> n >> k;
	while(k--){
		cin >> a >> x >> p;
		if(a==1){
			arr[p]+=x;
			if(p!=n+1) sum+=x, mi=max(mi,arr[p]);
		}
		else{
			c=(sum+p)/n;
			if((sum+p)%n) c++;
			c>=arr[n+1]+x || mi>=arr[n+1]+x ? cout << "NO\n" : cout << "YES\n";
		}
	}
}