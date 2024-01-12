#include <iostream>
using namespace std;
typedef long long ll;
ll arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	ll n, k, a, b, c;
	cin >> n >> k;
	while(k--){
		bool check=false;
		cin >> a >> b >> c;
		if(a==1) arr[c]+=b;
		else{
			for(int i=1; i<=n; i++){
				if(arr[i]+c<arr[n+1]+b){
					check=true;
					break;
				}
			}
			!check ? cout << "NO\n" : cout << "YES\n";
		}
	}
}