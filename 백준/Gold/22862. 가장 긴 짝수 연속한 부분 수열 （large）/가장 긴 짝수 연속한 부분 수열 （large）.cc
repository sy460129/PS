#include <iostream>
#include <queue>
using namespace std;
int arr[1000001];
queue<int>q;
int main(){
	int n, k, t=0, ans=0, c=0, c2=0; cin >> n >> k;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++){
		if(arr[i]%2){
			q.push(c2);
			c2=0, t++;
			if(t>k){
				ans=max(ans,c);
				c-=q.front(); q.pop();
				t--;
			}
		}
		else c++, c2++;
	}
	ans=max(ans, c);
	cout << ans;
}