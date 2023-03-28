#include <iostream>
#include <queue>
using namespace std;
int main(){
	int t, n, m, k, j; cin >> t;
	while(t--){
		int sum=0, cnt=0;
		cin >> n >> m >> k;
		int* arr=new int[n];
		queue<int>q;
		for(int i=0; i<n; i++) cin >> arr[i];
		for(int i=0; i<n+m-1; i++){
			j=i%n;
			sum+=arr[j];
			q.push(arr[j]);
			if(q.size()!=m && sum>=k) sum-=q.front(), q.pop();
			else if(q.size()==m){
				if(sum<k) cnt++;
				if(q.size()==n) break;
				sum-=q.front(), q.pop();
			}
		}
		cout << cnt << "\n";
	}
}