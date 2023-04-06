#include <iostream>
#include <queue>
#include <set>
using namespace std;
int arr[3000001];
int check[3001];
set<int>s;
queue<int>q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n, d, k, c, cnt=0, ans=0; cin >> n >> d >> k >> c;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++){
		while(q.size()!=k){
			if(i+cnt>=n){
				q.push(arr[i+cnt-n]);
				s.insert(arr[i+cnt-n]);
				check[arr[i+cnt-n]]++;
			}
			else{
				q.push(arr[i+cnt]);
				s.insert(arr[i+cnt]);
				check[arr[i+cnt]]++;
			}
			cnt++;
		}
		!check[c] ? ans=max(ans,(int)s.size()+1) : ans=max(ans, (int)s.size());
		if(check[q.front()]==1) s.erase(q.front());
		check[q.front()]--;
		q.pop();
		cnt--;
	}
	cout << ans;
}