#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, x, y, m, ans; cin >> t;
	while(t--){
		cin >> n;
		pair<int,int>* arr=new pair<int,int>[n];
		for(int i=0; i<n; i++){
			cin >> x >> y;
			arr[i]={x,y};
		}
		sort(arr, arr+n);
		m=arr[0].second, ans=1;
		for(int i=1; i<n; i++){
			if(m>arr[i].second) m=arr[i].second, ans++;
		}
		delete arr;
		cout << ans << "\n";
	}
}